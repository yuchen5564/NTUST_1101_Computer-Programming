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
    for (int i = 0; i < a - 1; i++) {   //���@��
        for (int j = i; j < a; j++) {   //��l�ƽ��y�P�e�����Ƥ��
            if (arr[i] > arr[j]) {  //�e���Ƥj������==>���洫��
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //----------------------------------
    int repeated[50] = { 0 };   //�������ƶ�
    int count = 0;  //�������ƶ��ƶq
    for (int i = 1; i < a; i++) {   //�����e�P�e�@�O�_�ۦP(�Ƨǫ�A�Ѥj��p)
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
    if (count == 0) {   //�����L����
        printf("No repeated number!");
    }

    //judge format
    for (int i = 0; i < count; i++) {
        if (i == (count - 1)) {     //�榡��X(�������i�H���ť�)
            printf("%d", repeated[i]);
        }
        else {
            printf("%d ", repeated[i]);
        }
    }

    return 0;
}