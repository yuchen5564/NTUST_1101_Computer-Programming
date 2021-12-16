#include <stdio.h>

int main()
{
	int c;
	char a = 'A';
	scanf_s("%d", &c);
	for (int i = 0; i < c; i++) {			//à蔼
		for (int j = c - i-1; j > 0; j--) {	//计秖
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {//ダ计秖
			printf("%c", a);
		}
		a += 1;	//传ダ
		if (i != (c - 1) ){
			printf("\n");	//传︽
		}
		
	}
    return 0;
}