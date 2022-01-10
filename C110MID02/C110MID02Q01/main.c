#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

//int main()
//{
//	char str[21] = { '\0' };
//	scanf("%s", str);
//	int len = strlen(str);
//	for (int k = 0; k < len; k++) {
//		int h = str[k]-'0';
//		for (int i = 0; i < h; i++) {
//			for (int j = h - i - 1; j > 0; j--) {	//计秖
//				printf(" ");
//			}
//		}
//
//	}
//    return 0;
// }

int main()
{
	char str[21] = { '\0' };
	scanf("%s", str);
	int len = strlen(str);

	for (int j = 0; j < len; j++) {
		int c = 0;
		c = str[j] - '0';
		int a = 1;

		for (int i = 0; i < c; i++) {			//à蔼
			for (int k = 0; k < i + 1; k++) {//ダ计秖
				printf("%d", a);
			}
			a += 1;	//传ダ
			printf("\n");	//传︽
		}
		a -= 2;
		for (int i = c - 2; i > 0; i--) {
			for (int k = 0; k < i + 1; k++) {//ダ计秖
				printf("%d", a);
			}
			a--;
			printf("\n");
		}
	}
	printf("1");
	

	return 0;
}
