#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>

#ifndef USERSPACE
#define main ukl_main
#endif

int main(void) {
    FILE        *f = fopen("/etc/passwd", "r");
    ssize_t     ret;
    char        buf[256] = { 0 };

    if (f == NULL)
    {
        fputs("Cannot open /etc/passwd\n", stderr);
        return 1;
    }

    while ((ret = fread(buf, 1, sizeof(buf), f)))
        fwrite(buf, ret, 1, stdout);

    fclose(f);
    return 0;
}
