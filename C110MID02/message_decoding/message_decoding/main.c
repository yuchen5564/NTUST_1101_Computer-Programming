#pragma warning (disable:4996)
#pragma warning (disable:6031)

#include <stdio.h>
#include <string.h>

int getword(char* p) {
	int ch = 0;
	while ((ch = getchar()) != ' ') {
		*p = ch;
		p++;
		if (ch == '\n') {
			return 0;
		}
	}
	return 1;
}

void clear(char* p) {
	int len = strlen(p);
	for (int i = 0; i < len; i++) {
		p[i] = '\0';
		//printf(".");
	}
}

void output(char* p) {
	for (p; *p != '\0'; p++) {
		printf("%c", *p);
	}
	printf("\n");
}

int getmessage(char* word, char* message) {
	int alphabet = 0;
	int n = 0;
	char* p;
	do {
		n = getword(word);
		int len = strlen(word);
		if (len < (alphabet + 1)) {
			continue;
		}
		if (word[0] == '\n') {
			return 0;
		}
		message[alphabet] = word[alphabet];
		clear(word);
		alphabet++;
	} while (n);

}

int main() {
	char word[31] = { '\0' }, message[101] = { '\0' };
	int num = 0;
	scanf("%d", &num);
	getchar();
	getchar();
	for (int i = 0; i < num; i++) {
		int n = 1;
		printf("Case #%d:\n", i + 1);
		while (n) {
			n = getmessage(&word, &message);
			if (n != 0) {
				output(&message);
			}
			clear(&message);
		}
		//getchar();
	}
	
	



	return 0;
}