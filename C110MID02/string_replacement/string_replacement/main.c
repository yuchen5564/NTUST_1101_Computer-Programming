#pragma warning (disable:4996)
#pragma warning (disable:6031)

#include <stdio.h>
#include <string.h>

void getstr(char* p) {
	int ch = 0;
	while ((ch = getchar()) != '\n') {
		*p = ch;
		p++;
	}
}

int main() {
	char s1[51] = { '\0' }, s2[51] = { '\0' }, s3[51] = { '\0' };
	getstr(&s1);
	getstr(&s2);
	getstr(&s3);

	int len = strlen(s2);

	char* ret;
	ret = strstr(s1, s2);
	while (ret) {
		*ret = '.';
		ret = strstr(s1, s2);
	}

	for (char* p = &s1; *p != '\0'; p++) {
		if (*p == '.') {
			p += len-1;
			printf("%s", s3);
		}
		else {
			printf("%c", *p);
		}
		
	}
	printf("\n");

	return 0;
}