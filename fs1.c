#include <unistd.h>
#include <fcntl.h>

#ifndef USERSPACE
# define main ukl_main
#endif

int main(void) {
	char        buf[256] = { 0 };
	int         fd = open("/etc/passwd", O_RDONLY);
	ssize_t     ret;

	if (fd == -1)
		return 1;

	while ((ret = read(fd, buf, sizeof(buf))))
	{
		buf[ret] = 0;
		write(1, buf, ret);
	}

	close(fd);

	return 0;
}
