#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

void getstr(char* p,char*p2,char*p3) {
	int ch = 0;
	while ((ch = getchar()) != '\n') {
		*p = ch;
		p++;
	}
	getchar();
	while ((ch = getchar()) != '\n') {
		*p2 = ch;
		p2++;
	}
	while ((ch = getchar()) != '\n') {
		*p3 = ch;
		p3++;
	}
}

int main()
{
	char s1[101] = { '\0' }, s2[51] = { '\0' }, s3[51] = { '\0' }, out[101] = { '\0' };
	getstr(&s1, &s2, &s3);
	char* ret, * p, * outp,* p3;
	int len2 = strlen(s2);
	
	ret = strstr(s1, s2);
	while (ret) {
		outp = &out;
		for (p = &s1; *p != '\0'; p++) {
			if (p == ret - 1) {
				*outp = '.';
				outp++;
				p = ret + len2-1;
			}
			else {
				*outp = *p;
				outp++;
			}
		}
		ret = strstr(out, s2);
		if (ret) {
			char* pp;
			pp = &s1;
			int len1 = strlen(s1);
			for (int i = 0; i < len1; i++) {
				s1[i] = '\0';
			}
			for (outp = &out; *outp != '\0'; outp++) {
				*pp = *outp;
				pp++;
			}
			int len_out = strlen(out);
			for (int i = 0; i < len_out; i++) {
				out[i] = '\0';
			}
			ret = strstr(s1, s2);
		}

		
	}
	int len3 = strlen(s3);
	for (outp = &out; *outp != '\0'; outp++) {
		if (*outp == '.') {
			*outp++;
			printf("%s", s3);
		}
		printf("%c", *outp);
	}
	printf("\n");
    return 0;
}