#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int find_index(int findnum,int a[],int num) {
    int index = 0;
    for (int i = 0; i < num; i++) {
        if (findnum == a[i]) {
            index = i;
            return index;
        }
    }
}
int main()
{
    int n = 0;
    int input_arr[10] = { 0 }, sort_arr[10] = { 0 }, index_arr[10] = { 0 };
    scanf_s("%d", &n);
    //input
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &input_arr[i]);
        sort_arr[i]=input_arr[i];
    }
    //sort
    int temp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            if (sort_arr[i] > sort_arr[j]) {
                temp = sort_arr[i];
                sort_arr[i] = sort_arr[j];
                sort_arr[j] = temp;
            }
        }
    }
    //find index
    for (int i = 0; i < n; i++) {
        index_arr[i] = find_index(sort_arr[i], input_arr, n);
    }
    //judge format
    for (int i = 0; i < n; i++) {
        if (i != (n - 1)) {
            printf("%d ", index_arr[i]);
        }
        else {
            printf("%d", index_arr[i]);
        }
        
        
        
    }
    

    return 0;
}