#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int c;
	scanf_s("%d", &c);
	if (!(c >= 2 && c <= 20)) {
		printf("Invalid input\n");
		return 0;
	}
	for (int i = 0; i < c; i++) {			//�T���ΰ���
		//for (int j = 0; j < c - i - 1; j++) {	//�Ů�ƶq
		//	printf("*");
		//}
		//for (int k = 2 * i + 1; k > 0; k--) {
		//	printf(" ");
		//}
		for (int j =  i; j > 0; j--) {	//�Ů�ƶq
			printf(" ");
		}
		for (int k = 0; k < 2 * (c-i-1) +1; k++) {//�r���ƶq
			printf("*");
		}
		if (i != (c - 1)) {
			printf("\n");	//����
		}

	}
	printf("\n");

	//�����T����
	for (int i = 1; i < c; i++) {			//�T���ΰ���
		for (int j = c - i - 1; j > 0; j--) {	//�Ů�ƶq
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {//�r���ƶq
			printf("*");
		}
		if (i != (c - 1)) {
			printf("\n");	//����
		}

	}
    return 0;
}