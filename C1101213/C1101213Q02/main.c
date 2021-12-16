#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();

    for (int j = 0; j < n; j++) {
        char alphabet = { ' ' };
        int num = 0;
        char out[201] = { '\0' };

        char* p;
        p = &out;

        int ch = 0;
        while ((ch = getchar()) != '\n') {
            alphabet = ch;
            scanf("%d", &num);
            for (int i = 0; i < num; i++) {
                *p = alphabet;
                p++;
            }
        }

        int len = strlen(out);
        printf("Case %d: ", j + 1);
        for (int i = 0; i < len; i++) {
            printf("%c", out[i]);
        }
        printf("\n");
    }


    return 0;
}




/*
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    int out1[50][201] = { '\0' };
    for (int j = 0; j < n; j++) {
        char alphabet = { ' ' };
        int num = 0;
        int total = 0;
        int ch = 0;
        while ((ch = getchar()) != '\n') {
            alphabet = ch;
            scanf("%d", &num);
            
            for (int i = total; i < total+num; i++) {
                out1[j][i] = alphabet;
            }
            total += num;
        }

    }

    //output
    for (int i = 0; i < 50; i++) {
        if (out1[i][0] == '\0') {
            break;
        }
        printf("Case %d: ", i + 1);
        for (int j = 0; j < 201; j++) {
            if (out1[i][j] == '\0') {
                break;
            }
            printf("%c", out1[i][j]);
        }
        printf("\n");
    }


    return 0;
}
*/