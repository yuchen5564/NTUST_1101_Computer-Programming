#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#define MAX 60

void inToPostfix(char*, char*,int); // 中序轉後序 
int priority(char); // 運算子優先權

int main(void) {
    char infix[MAX] = { '\0' };
    char postfix[MAX] = { '\0' };
    
    //printf("中序運算式：");
    scanf("%s", infix);
    int len = strlen(infix);
    inToPostfix(&infix[0], &postfix[0],len);
    len = strlen(postfix);

    for (char* p = &postfix[0]; p < &postfix[0] + len; p++) {
        printf("%c", *p);
    }
    

    return 0;
}

void inToPostfix(char* infix, char* postfix,int len) {
    char stack[MAX] = { '\0' };
    char* top;
    top = &stack[0];
    for (char* p = infix; p < infix + len; p++) {
        switch (*p) {
        case '(':
            top++;
            *top = *p;
            break;
        case'+':case'-':case'*':case'/':
            //printf("..\n");
            while (priority(*(top)) >= priority(*p)) {
                //printf("...\n");
                *postfix = *top;
                postfix++;
                top--;
            }    
            top++;
            *top = *p;
            break;
        case')':
            while (*top != '(') {
                *postfix = *top;
                postfix++;
                top--;
            }
            top--;
            break;
        default:
            //printf(".\n");
            *postfix = *p;
            postfix++;
        }
        
    }
    while (top > &stack[0]) {
        *postfix = *top;
        postfix++;
        top--;
    }
    
}

int priority(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    default:            return 0;
    }
}