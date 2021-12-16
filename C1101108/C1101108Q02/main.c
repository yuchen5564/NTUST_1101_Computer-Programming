#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int gcd(int m, int n)	//輾轉相除法
{
	int t = 1;
	while (t != 0)
	{
		t = m % n;
		m = n;
		n = t;
	}
	return m;
}
/*
int B2D(int n) {
	int ex = 0, dec = 0,temp=0,t=0;
	while (n > 0) {
		temp = n % 10;
		
		dec += temp* pow(2, ex);
		ex++;
		n = n / 10;
	}
	return dec;
}*/
/*
int bintodeci(char* s){
	int res = 0, i;
	char* p;
	i = 1;
	p = s;
	while (*p != '\0')p++;//p一直指向字符串最後的反斜槓0，只為了從右往左運算
	while (p != s)	{
		p--;
		res = res + i * (*p - '0');
		i *= 2;//位權等比遞增，1,2,4,8,16
	}
	return res;//最後結果加上符號即可

}*/

int bintodeci(char* s) {
	int len = strlen(s);
	int dec = 0;
	for (int i = 0; i < len; i++) {
		dec += (s[i]-'0') * pow(2, (len - i - 1));
	}
	return dec;
}

int main()
{
	int n = 0,x =0,cc=0,dec_a=0,dec_b=0, g=0;
	//int s1 = 0, s2 = 0;
	char s1[31], s2[31];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s1);
		scanf("%s", s2);
		dec_a = bintodeci(s1);
		dec_b = bintodeci(s2);
		g = gcd(dec_a, dec_b);
		//printf("%d\n", g);
		if (g==1) {
			printf("Pair #%d: Love is not all you need!\n", i + 1);
		}
		else if((dec_a % g == 0) && (dec_b % g == 0)){
			printf("Pair #%d: All you need is love!\n", i + 1);
		}
	}
    return 0;
}