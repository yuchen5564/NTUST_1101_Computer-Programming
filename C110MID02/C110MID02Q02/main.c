#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

void bubble(float *arr1,float *arr2, int len) {
	float temp = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i; j < len; j++) {
			if (arr1[i] > arr1[j]) {	//比較兩項大小
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
			if (arr1[i] == arr1[j]) {
				if (arr2[i] > arr2[j]) {	//比較兩項大小
					temp = arr2[i];
					arr2[i] = arr2[j];
					arr2[j] = temp;
				}
			}
		}
	}

}

int main()
{
	int n = 0;
	float arr1[11] = { 0 }, arr2[11] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%f %f", &arr1[i], &arr2[i]);
	}
	bubble(&arr1, &arr2, n);
	for (int i = 0; i < n; i++) {
		printf("%.2f %.2f\n", arr1[i], arr2[i]);
	}
    //printf("Hello world!");
    return 0;
}
