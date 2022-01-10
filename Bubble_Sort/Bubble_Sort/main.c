#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int a[100] = { 0 };

void bubble(int arr[], int len) {
    int temp = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {	//比較兩項大小
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}

int main() {
    int n = 0;
    scanf("%d", &n); // 輸入個數
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    bubble(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}