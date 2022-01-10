#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

void getstr(char* p) {
	int ch = 0;
	while ((ch = getchar()) != '\n') {
		*p = ch;
		p++;
	}
}

void search(char* p) {
	char temp[31] = { '\0' };
	char* t;
	t = *temp;
	int ch = 0;
	int n = 1;
	while ((ch = getchar()) != '\n') {
		if (ch == ' ') {
			int len = strlen(temp);
			//printf("%d", len);
			if (len > n) {
				*p = temp[n - 1];
				p++;
				n++;
			}
			for (int i = 0; i < len; i++) {
				temp[i] = '\0';
			}
			//printf("%c\n", *p);
			
		}
		else {
			*temp = ch;
		}
	}
}

int main()
{
	char str[31] = { '\0' };
	search(*str);
	for (char* p = &str; *p != '\0'; p++) {
		printf("%c", *p);
	}
   // printf("Hello world!");
    return 0;
}