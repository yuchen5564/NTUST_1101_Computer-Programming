#include <stdio.h>

int main()
{
    float a, b;
    char c;
    scanf_s("%f", &a);
    scanf_s(" %c", &c, 1);
    scanf_s(" %f", &b);
    switch (c) {
    case '+':
        printf("%.2f + %.2f = %.2f", a, b, a + b);
        break;
    case '-':
        printf("%.2f - %.2f = %.2f", a, b, a - b);
        break;
    case '*':
        printf("%.2f * %.2f = %.2f", a, b, a * b);
        break;
    case '/':
        if (b == 0) {
            printf("Division by zero");
        }
        else {
            printf("%.2f / %.2f = %.2f", a, b, a / b);
        }
        break;
    }
    return 0;
}