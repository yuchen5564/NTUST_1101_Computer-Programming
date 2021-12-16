#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int fibonacci(int a[], int len) {
    int num = 0;
    num = a[len - 1] + a[len - 2];
    return num;
}


int main()
{
    int n = 0;
    scanf_s("%d", &n);
    n += 1;
    if (n < 0) {
        printf("\"Invalid input\"");
        return 0;
    }
    int arr[31] = { 0,1 };  //初始化前兩位數，後面未指定皆為0
    for (int i = 2; i < n; i++) {
        arr[i] = fibonacci(arr, i);
    }
    printf("%d", arr[n - 1]);
    return 0;
}