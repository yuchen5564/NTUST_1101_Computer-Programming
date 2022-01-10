#pragma warning (disable:4996)
#pragma warning (disable:6031)
#include <stdio.h>

#define INT_SIZE 32

void D2B(int num, int* bit) {
	int index = INT_SIZE - 1;
	while (index >= 0) {
		bit[index] = num & 1;
		index--;
		num >>= 1;
	}
}

void output_bit(int* bit) {
	for (int i = 0; i < INT_SIZE; i++) {
		printf("%d", bit[i]);
	}
	printf("\n");
}

int reverse_bits(int x)
{
	x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
	x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
	x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
	x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
	x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);

	return x;
}

int count_bits(int x)
{
	x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
	x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
	x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
	x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
	x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
	return x;
}

int main() {
	int num = 0, index = INT_SIZE - 1;
	int bit[INT_SIZE] = { 0 };

	scanf("%d", &num);

	D2B(num, &bit);

	output_bit(&bit);

	printf("Zeros: %d\n", INT_SIZE - count_bits(num));
	printf("Ones: %d\n", count_bits(num));

	//=========================

	num = reverse_bits(num);

	D2B(num, &bit);

	output_bit(&bit);

	printf("%d\n", num);

	return 0;
}


/*
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int reverse_bits(int x)
{
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);

    return x;
}

int count_bits(int x)
{
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

int D2B(int n) {
    int index = 31;
    int p[32] = { 0 };
    if (n < 0) {
        n = ~n + 1;
        p[0] = 1;
        while (index > 0) {
            p[index] = n & 1;
            index--;
            n >>= 1;
        }
        index = 31;
        short flag = 0;
        while (index > 0) {
            if (flag == 0 && p[index] == 1) {
                flag = 1;
            }
            else if (flag == 1) {
                p[index] ^= 1;
            }
            index--;
        }
    }
    else {
        while (index > 0) {
            p[index] = n & 1;
            index--;
            n >>= 1;
        }
    }
    while (index < 32) {
        printf("%d", p[index]);
        index++;
    }
    printf("\n");
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    D2B(num);
    int bit_1 = count_bits(num);
    //num = ~num + 1; // ABS
    //printf(">>> %d\n", num);
    printf("Zeros: %d\n", 32 - bit_1);
    printf("Ones: %d\n", bit_1);

    int reverse_num = reverse_bits(num);
    D2B(reverse_num);
    printf("%d\n", reverse_num);
    return 0;
}
*/

/*
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	int bin[33] = { 0 };
	int flag = 0;	//正負號
	scanf("%d", &n);

	//判斷正負號
	if (n < 0) {
		flag = 1;
		n = n * (-1);
	}

	//轉換二進制
	int* p;
	p = &bin;
	while (n > 0) {
		*p = n % 2;
		n = n / 2;
		p++;
	}
	
	//負數取二的補數
	if (flag == 1) {
		for (int i = 1; i < 32; i++) {
			if (bin[i] == 1) bin[i] = 0;
			else bin[i] = 1;
		}
	}

	//輸出+計算位元數量
	int zero = 0, one = 0;
	for (int i = 31; i >= 0 ; i--) {
		printf("%d", bin[i]);
		if (bin[i] == 1) one++;
		else zero++;
	}
	printf("\n");
	printf("Zeros: %d\nOnes: %d\n", zero, one);

	//反轉輸出+計算反轉後的數值
	flag = bin[0];
	int sum = 0;

	for (int i = 0; i < 32; i++) {
		printf("%d", bin[i]);
		if (flag == 1) {
			if (i == 0) continue;
			if (bin[i] == 1) bin[i] = 0;
			else bin[i] = 1;
		}
		sum += bin[i] * pow(2, 31 - i);
	}

	if (flag == 1) printf("\n-%d\n", sum + 1);
	else printf("\n%d\n", sum);

    return 0;
}
*/