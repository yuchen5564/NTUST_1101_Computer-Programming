#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

//接收字串輸入(以換行為分隔)
//(*p) = (接收陣列第一位)
void getstr(char* p) {
    int ch = 0;
    while ((ch = getchar()) != '\n') {
        *p = (char)ch;
        p++;
    }
}

//編碼(Ascii位移n)
//(*in, len, n) = (陣列第一位, 陣列總長, 位移數量)
void change(char* in, int len, int n) {
    for (char* p = in; p < &in + len; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p += n;
            if (*p > 'Z') { //超過校正
                *p -= 26;
            }
        }
        if (*p >= 'a' && *p <= 'z') {
            *p += n;
            if (*p > 'z') { //超過校正
                *p -= 26;
            }
        }
    }
}

int main()
{
    char str[100] = { ' ' };
    int num = 0;
    getstr(&str[0]);

    scanf("%d", &num);  //acsii位移數量
    
    change(&str, strlen(str), num % 26); 

    printf("%s\n", str);

    return 0;
}