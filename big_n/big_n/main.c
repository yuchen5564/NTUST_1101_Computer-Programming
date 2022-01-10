#pragma warning (disable:4996)
#pragma warning (disable:6031)

#include <stdio.h>
#include <string.h>

//�����r���J(�H���欰���j)
void getStr(char* p) {
	int ch = 0;
	while ((ch = getchar()) != '\n') {
		*p = ch;
		p++;
	}
	*p = '\0';
}

//���Φr��
int cutStr(char* in, char* out, char* ret) {
	int f = 0;
	for (char* p = in; p >= ret; p--) {
		if (*p == '.') {
			f = 1;
		}
		*out = *p;
		out++;
	}
	return f;
}

//�}�C�k��
void moveRight(char* in, int len, int n) {
	for (int i = len; i >= 0; i--) {
		in[i + n] = in[i];
	}
	for (int i = 0; i < n; i++) {
		in[i] = 48;
	}
}

//����\0=>0
void change0(char* p) {
	if (*p == '\0') {
		*p = 48;
	}
}

//�[�k
void add(char* out, char* s1, char* s2, int len) {
	int carry = 0;
	for (int i = 0; i < len; i++) {
		if ((*(s1 + i) == '.') && (*(s2 + i) == '.')) {
			*(out + i) = '.';
			continue;
		}
		change0(s1 + i);
		change0(s2 + i);
		*(out + i) = *(s1 + i) + *(s2 + i) - '0' + carry;
		if (*(out + i) > '9') {
			*(out + i) -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
	}
	if (carry == 1) {
		*(out + len) = '1';
	}
}

//��k
void sub(char* out, char* s1, char* s2, int len) {
	int borrow = 0;
	for (int i = 0; i < len; i++) {
		if ((*(s1 + i) == '.') && (*(s2 + i) == '.')) {
			*(out + i) = '.';
			continue;
		}
		change0(s1 + i);
		change0(s2 + i);
		*(out + i) = *(s1 + i) - *(s2 + i) + '0' - borrow;
		if (*(out + i) < '0') {
			*(out + i) += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}
	}
	//�t�ƳB�z
	if (borrow == 1) {
		//printf(".\n");
		sub(out, s2, s1, len);
		*(out + len) = '-';
	}
}

//void multi(char* out, char* s1, char* s2, int len) {
//	for (int i = 0; i < len; i++) {
//
//	}
//}

//��X
void outPrint(char* p, int len) {
	int front = 0, back = 0;

	//�h���L�N�q��0
	for (int i = 0; i < len; i++) {
		if (*(p + i) != '0') {
			break;
		}
		back++;
	}
	if (*(p + back) == '.') {
		back++;
	}
	for (int i = len - 1; i >= 0; i--) {
		if (*(p + i) != '0') {
			break;
		}
		front++;
	}

	//��X
	for (int i = len - 1 - front; i >= back; i--) {
		printf("%c", *(p + i));
	}
	if ((front + back) == len) {
		printf("0");
	}
	printf("\n");
}


int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	for (int j = 0; j < n; j++) {
		char str[121] = { '\0' }, s1[62] = { '\0' }, s2[62] = { '\0' };
		getStr(&str);
		int len = strlen(str);
		char* p1, * p2;
		char sym = { '\0' };
		p1 = &s1[0];
		p2 = &s2[0];

		//==========================================
		//�M��B��Ÿ�
		char* ret;
		ret = strstr(str, "+");
		if (ret == NULL) ret = strstr(str, "-");
		sym = *ret;

		//==========================================
		//���Φr��+�ɤp���I
		int flag = 0;
		flag = cutStr(ret - 1, &s1, &str);				//����s1
		if (flag == 0) {
			moveRight(&s1, strlen(s1), 1);
			s1[0] = '.';
		}

		flag = cutStr(&str[len - 1], &s2, ret + 1);		//����s2
		if (flag == 0) {
			moveRight(&s2, strlen(s2), 1);
			s2[0] = '.';
		}

		//=========================================
		//�M��str
		for (int i = 0; i < len; i++) str[i] = '\0';

		//=========================================
		//�p�Ʀ�ƳB�z
		char* ret1, * ret2;
		ret1 = strstr(s1, ".");
		ret2 = strstr(s2, ".");
		int len1 = ret1 - &s1[0];
		int len2 = ret2 - &s2[0];
		if (len1 > len2) moveRight(&s2, strlen(s2), len1 - len2);
		else moveRight(&s1, strlen(s1), len2 - len1);

		//=========================================
		//�M�w�`��
		if (strlen(s1) >= strlen(s2)) len = strlen(s1);
		else len = strlen(s2);

		//=========================================
		// �B��
		if (sym == '+') add(&str, &s1, &s2, len);
		else if(sym == '-') sub(&str, &s1, &s2, len);

		//=========================================
		//��X
		outPrint(&str, strlen(str));
	}

	return 0;
}