#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);

	int a[100] = { 0 }, b[100] = { 0 }, sum[100] = { 0 };
	
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &b[i]);
	}
	int c = 1;
	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < n; j++) {
			int t1 = (i / n)*n+j;
			int t2 = i% n +j*n ;
			//printf("%d, %d\n", i, j);
			//sum[i] += a[2*(i / n) + j] * b[(i % n)*n + j];
			sum[i] += a[t1] * b[t2];
			//printf("%d, %d | %d, %d\n", t1, t2,a[t1], b[t2]);
		}
		//printf("----\n");
	}
	
	for (int i = 0; i < n * n; i++) {

		if ((i + 1) % n == 0) {
			printf("%d\n", sum[i]);
		}
		else {
			printf("%d ", sum[i]);
		}
	}
	return 0;
}