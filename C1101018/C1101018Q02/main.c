#include <stdio.h>

int main()
{
	int c;
	char a = 'A';
	scanf_s("%d", &c);
	for (int i = 0; i < c; i++) {			//三角形高度
		for (int j = c - i-1; j > 0; j--) {	//空格數量
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {//字母數量
			printf("%c", a);
		}
		a += 1;	//換下一個字母
		if (i != (c - 1) ){
			printf("\n");	//換行
		}
		
	}
    return 0;
}