#pragma warning (disable:4996)
#pragma warning (disable:6031)
#include <stdio.h>
/*
* 輸入
* 轉換"."to"0"
* 計算
* 輸出
*/

int except(int i, int j, int n, int m) {
	if (i < 0) return 0;
	if (j < 0) return 0;
	if (i > n - 1) return 0;
	if (j > m - 1) return 0;
	return 1;
}

int main()
{
	int n = 0, m = 0;//n = ROW, m = COL
	int num = 1;
	scanf("%d %d", &n, &m);
	char arr[101][101] = { '\0' };
	getchar();
	while (n != 0 && m != 0) {
		int ch = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m + 1; j++) {
				scanf("%c", &arr[i][j]);
				if (arr[i][j] == '.') {
					arr[i][j] = '0';
				}
			}
		}

		//========================================
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '*') {
					if (except(i - 1, j - 1, n, m) && arr[i - 1][j - 1] != '*') arr[i - 1][j - 1]++;
					if (except(i - 1, j, n, m) && arr[i - 1][j] != '*') arr[i - 1][j]++;
					if (except(i - 1, j + 1, n, m) && arr[i - 1][j + 1] != '*') arr[i - 1][j + 1]++;
					if (except(i, j - 1, n, m) && arr[i][j - 1] != '*') arr[i][j - 1]++;
					if (except(i, j + 1, n, m) && arr[i][j + 1] != '*') arr[i][j + 1]++;
					if (except(i + 1, j - 1, n, m) && arr[i + 1][j - 1] != '*') arr[i + 1][j - 1]++;
					if (except(i + 1, j, n, m) && arr[i + 1][j] != '*') arr[i + 1][j]++;
					if (except(i + 1, j + 1, n, m) && arr[i + 1][j + 1] != '*') arr[i + 1][j + 1]++;
				}
			}
		}

		//========================================
		//輸出
		printf("Field #%d:\n", num);
		num++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m + 1; j++) {
				printf("%c", arr[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m + 1; j++) {
				arr[i][j] = '\0';
			}
		}
		printf("\n");
		scanf("%d %d", &n, &m);
		getchar();
	}
	
	
	return 0;
}