#include <stdio.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int calc(int (*pt_f)(int, int), int a, int b)
{
    return pt_f(a, b);
}
int main(int argc, char *argv[])
{
    int c = 0;
    if (*argv[1] == '+')
        c = calc(&add, 4, 3);
    else if (*argv[1] == '-')
        c = calc(&sub, 4, 3);
    else
        c = -1;
    printf("result: %d\n", c);
    return 0;
}