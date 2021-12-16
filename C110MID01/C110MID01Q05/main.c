#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n = 0, r = 0;// n=number, r=N*N
	scanf("%d", &n);
	scanf(" %d", &r);
	int sum[100] = { 0 };
	int temp = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < r * r;i++) {
			scanf("%d", &temp);
			sum[i] += temp;
		}
		/*for (int i = 0; i < r * r; i++) {
			printf("%d ", sum[i]);
		}
		printf("\n");*/
	}
	
	for (int i = 0; i < r * r; i++) {
		
		if ((i + 1) % r == 0) {
			printf("%d\n", sum[i]);
		}
		else {
			printf("%d ", sum[i]);
		}
	}
	
    return 0;
}