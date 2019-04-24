#include <stdio.h>

#ifndef USERSPACE
#define main ukl_main
#endif

typedef struct {
    char a;
    char *b;
    int c;
} test_t;

int main(void) {
    char        str[250];
    test_t      test = {
        .a = 'a',
        .b = "Hello!",
        .c = 10
    };

    printf("a = %c, b = %s, c = %d\n", test.a, test.b, test.c);
    snprintf(str, sizeof(str), "a = %c, b = %s, c = %d\n", test.a, test.b, test.c);
    puts(str);
    return 0;
}
