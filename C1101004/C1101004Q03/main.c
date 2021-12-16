#include <stdio.h>

int main()
{
    int a, b = 0;
    char c;
    scanf_s("%d", &a);
    scanf_s(" %c", &c, 1);
    scanf_s(" %d", &b);

    printf("%d %c %d", a,c,  b);

    return 0;
}