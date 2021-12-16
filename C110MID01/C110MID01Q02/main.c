#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n = 0;
	int flag = 0;
	scanf("%d", &n);
	if (n == 1) {
		printf("It is an ugly number.\n");
		return 0;
	}
	for (int i = 2; i < n-1; i++) {
		if ((i % 2 == 0) || (i % 3 == 0) || (i % 5) == 0) {
			continue;
		}
		if (n % i == 0) {
			flag = 1;
		}
	}
	if (flag == 1) {
		printf("It is not an ugly number.\n");
	}
	else {
		printf("It is an ugly number.\n");
	}
    return 0;
}