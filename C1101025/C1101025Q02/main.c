#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    //-----sort-------------------------
    int a = 0, temp = 0;
    int arr[100] = { 0 };
    scanf_s("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf_s("%d", &arr[i]);
    }

    //sort
    for (int i = 0; i < a - 1; i++) {   //取一數
        for (int j = i; j < a; j++) {   //其餘數輪流與前取之數比較
            if (arr[i] > arr[j]) {  //前取數大於後取數==>執行換位
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //----------------------------------
    int repeated[50] = { 0 };   //紀錄重複項
    int count = 0;  //紀錄重複項數量
    for (int i = 1; i < a; i++) {   //比較當前與前一是否相同(排序後，由大到小)
        if (arr[i] == arr[i - 1]) {
            int flag = 0;   //是否已重複(每輪重製)
            for (int j = 0; j < count; j++) {   //判斷是否已經存在重複陣列中
                if (arr[i] == repeated[j]) {    //當前與重複陣列逐一比對，如果重複，flag = 1
                    flag = 1;
                }
            }
            if (flag == 0) {    //flag = 0，記錄至重複陣列
                repeated[count] = arr[i];
                count += 1;
            }
        }
    }
    if (count == 0) {   //全部無重複
        printf("No repeated number!");
    }

    //judge format
    for (int i = 0; i < count; i++) {
        if (i == (count - 1)) {     //格式輸出(末尾不可以有空白)
            printf("%d", repeated[i]);
        }
        else {
            printf("%d ", repeated[i]);
        }
    }

    return 0;
}