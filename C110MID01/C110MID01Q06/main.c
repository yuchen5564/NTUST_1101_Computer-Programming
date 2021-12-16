#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	char num[1000];
	scanf("%s", num);
	int len = strlen(num);
	
	int odd = 0, even = 0;
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			even += (num[i] - '0');
		}
		else {
			odd += (num[i] - '0');
		}
	}
	
	if (abs(odd - even) % 11 == 0) {
		printf("%s is a multiple of 11.\n", num);
		
	}
	else {
		printf("%s is not a multiple of 11.\n", num);
		
	}
	
    return 0;
}


