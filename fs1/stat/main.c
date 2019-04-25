#include <stdio.h>
#include <sys/stat.h>

#ifndef USERSPACE
#define main ukl_main
#endif

int main(void)
{
    struct stat st = { 0 };

    if (stat("/etc/passwd", &st) != 0)
    {
        fprintf(stderr, "Cannot stat() /etc/passwd\n");
        return 1;
    }

    printf("Size of /etc/passwd: %zu bytes\n", st.st_size);
    return 0;
}
