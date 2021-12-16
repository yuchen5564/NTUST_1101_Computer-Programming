#include <stdio.h>

int main()
{
	int a1, a2, a3, a4, b1, b2, b3, b4;
	scanf_s("%d %d %d %d", &a1, &a2, &a3, &a4);
	scanf_s("%d %d %d %d", &b1, &b2, &b3, &b4);
	printf("%d %d\n", a1 + b1, a2 + b2);
	printf("%d %d\n", a3 + b3, a4 + b4);
	return 0;
}