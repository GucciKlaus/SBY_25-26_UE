#include <stdio.h>

union U
{
    int i;
    char c;
    double d;
};

struct S
{
    int i;
    char c;
    double d;
};

int main()
{
    union U u;
    struct S s;

    u.i = 42; // wir setzen INT
    s.i = 42;
    printf("i = %d\n", u.i); // korrekt
    printf("i = %d\n", s.i);

    u.d = 3.14; // jetzt DOUBLE
    s.d = 3.14;
    printf("d = %f\n", u.d); // korrekt
    printf("d = %f\n", s.d);

    u.c = 'A'; // jetzt CHAR
    s.c = 'A';
    printf("c = %c\n", u.c); // korrekt
    printf("c = %c\n", s.c);

    printf("%d\n", u.c); // 65 -> 1 byte geändert von 3.14 aufA, weil nur auf der Char ebene geändert wird
    printf("%f\n", u.d); // 3.140000 -> das zuletzte bleibt normal im speicher
    printf("%d\n", u.i); // ruf die ersten 4 byte wieder auf weil es ja die int größe abruft, das ergibt gulasch weil noch immer 'A' im speicher steht
    printf("%d\n", s.c); // 65
    printf("%f\n", s.d); // 3.14
    printf("%d\n", s.i); // 42

    return 0;
}
