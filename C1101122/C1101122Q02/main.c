#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

void getstr(char* p) {
    int ch = 0;
    while ((ch = getchar()) != '\n') {
        *p = (char)ch;
        p++;
    }
}

int main()
{
    char s1[40] = { ' ' }, s2[40] = { ' ' };
    int len1, len2;

    getstr(&s1[0]); //input
    getstr(&s2[0]);

    len1 = strlen(s1);
    len2 = strlen(s2);

    if (len2 > len1) {  //s2長度大於s1長度
        printf("Invalid pattern\n");
        return 0;
    }

    char* ret;
    ret = strstr(s1, s2);   //比較字串，回傳記憶體位置
    
    if (!ret) {         //回傳值為0==沒有相同
        printf("Pattern not found\n");
        return 0;
    }

    char* p;
    p = &s1[0];

    for (p; p < &s1[len1]; p++) {
        if (p == ret) {
            p += len2;  //跳過重複位置
        }
        printf("%c", *p);
    }

    printf("\n");
    return 0;
}