#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

int count(char* p,int *flag) {
    switch (*p) {
    case 'I':
        return 1;
    case'V':
        if (*(--p) == 'I') {
            *flag = 1;
            return 4;
        }
        return 5;
    case'X':
        if (*(--p) == 'I') {
            *flag = 1;
            return 9;
        }
        return 10;
    case'L':
        if (*(--p) == 'X') {
            *flag = 1;
            return 40;
        }
        return 50;
    case'C':
        if (*(--p) == 'X') {
            *flag = 1;
            return 90;
        }
        return 100;
    case'D':
        if (*(--p) == 'C') {
            *flag = 1;
            return 400;
        }
        return 500;
    case'M':
        if (*(--p) == 'C') {
            *flag = 1;
            return 900;
        }
        return 1000;
    }
}


void input(char* p) {
    int ch = 0;
    while (ch = getchar() != '\n') {
        *p = ch;
        p++;
    }
}

int main()
{
    char str[11] = { '\0' };
    int n = 0, len = 0;
    int flag = 0;
    scanf("%s", &str);
    len = strlen(str);

    for (char* p = &str[0]+len-1; p >= &str[0]; p--) {
        n += count(p, &flag);
        if (flag == 1) {
            flag = 0;
            p--;
        }
    }

    printf("%d\n", n);

    return 0;
}