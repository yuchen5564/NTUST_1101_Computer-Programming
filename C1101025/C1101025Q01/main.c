//#pragma warning(disable : 4996)
//#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int a = 0, temp = 0;
    int arr[100] = { 0 };
    scanf_s("%d", &a);

    //input
    for (int i = 0; i < a; i++) {
        scanf_s("%d", &arr[i]);
    }

    //sort
    for (int i = 0; i < a - 1; i++) {
        for (int j = i; j < a; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //judge format
    for (int i = 0; i < a; i++) {
        if (i == (a - 1)) {
            printf("%d", arr[i]);
        }
        else {
            printf("%d ", arr[i]);
        }
        
    }
    printf("\n");

    return 0;
}