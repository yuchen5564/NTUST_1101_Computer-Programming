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
			if (arr[i] > arr[j]) {	//����ⶵ�j�p
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}


	int repeated[10] = { 0 };   //�������ƶ�
	int count = 0;  //�������ƶ��ƶq
	for (int i = 1; i <10; i++) {   //�����e�P�e�@�O�_�ۦP(�Ƨǫ�A�Ѥj��p)
		if (arr[i] == arr[i - 1]) {
			int flag = 0;   //�O�_�w����(�C�����s)
			for (int j = 0; j < count; j++) {   //�P�_�O�_�w�g�s�b���ư}�C��
				if (arr[i] == repeated[j]) {    //��e�P���ư}�C�v�@���A�p�G���ơAflag = 1
					flag = 1;
				}
			}
			if (flag == 0) {    //flag = 0�A�O���ܭ��ư}�C
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