#include <stdio.h>

int main()
{
	int c;
	char a = 'A';
	scanf_s("%d", &c);
	for (int i = 0; i < c; i++) {			//�T���ΰ���
		for (int j = c - i-1; j > 0; j--) {	//�Ů�ƶq
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {//�r���ƶq
			printf("%c", a);
		}
		a += 1;	//���U�@�Ӧr��
		if (i != (c - 1) ){
			printf("\n");	//����
		}
		
	}
    return 0;
}