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