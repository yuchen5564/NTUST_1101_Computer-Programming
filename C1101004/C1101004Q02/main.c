#include <stdio.h>

int main()
{
    float a, b = 0;
    scanf_s("%f", &a);
    scanf_s("%f", &b);
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
    return 0;
}