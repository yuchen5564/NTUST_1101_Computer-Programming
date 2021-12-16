#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	int temp = 0;
	for (int i = 0; i < 10 - 1; i++) {
		for (int j = i; j < 10; j++) {
			if (arr[i] > arr[j]) {	//比較兩項大小
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}


	int repeated[10] = { 0 };   //紀錄重複項
	int count = 0;  //紀錄重複項數量
	for (int i = 1; i <10; i++) {   //比較當前與前一是否相同(排序後，由大到小)
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
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += repeated[i];
	}
	printf("%d", sum);
    return 0;
}