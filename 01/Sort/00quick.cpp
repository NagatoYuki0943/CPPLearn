#include <iostream>

using namespace std;
/**
 * ��������,�ٶ���һ��ֵΪ�м�ֵ,�ȴ���������һ������С��,�ٴ������һ�����������,��������λ��,���i==j,���м�ֵ��i��ֵ����
 */
//��������
void UpQuickSort(int left, int right, int arr[]) {
    //���Ϊ��һ�����ʹ���������
    if (left >= right) {
        return;
    }
    int i, j, base, tmp;
    i = left;
    j = right;
    base = arr[left]; //ȡ����ߵ���Ϊ��׼
    while (i < j) {
        ///i��j�������
        //�ҵ����Ҳ�����һ��С��base����
        while (arr[j] >= base && i < j) {  //�ҵ�֮��Ż��˳�ѭ��
            j--;
        }
        //�ҵ����������һ������base����
        while (arr[i] <= base && i < j) { //�ҵ�֮��Ż��˳�ѭ��
            i++;
        }
        //�����������಻ͬ����
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    //��׼����λ,����i��λ�õ�ֵ�Ϳ�ʼ��׼λ�õ�ֵ����λ��
    arr[left] = arr[i];
    arr[i] = base;
    UpQuickSort(left, i - 1, arr); //��ߵݹ�
    UpQuickSort(i + 1, right, arr); //�ݹ��ұ�
}

//��������
void DownQuickSort(int left, int right, int arr[]) {
    //���Ϊ��һ�����ʹ���������
    if (left >= right) {
        return;
    }
    int i, j, base, tmp;
    i = left;
    j = right;
    base = arr[left]; //ȡ����ߵ���Ϊ��׼
    while (i < j) {
        ///i��j�������
        //�ҵ����Ҳ�����һ������base����
        while (arr[j] <= base && i < j) { //�ҵ�֮��Ż��˳�ѭ��
            j--;
        }
        //�ҵ����������һ��С��base����
        while (arr[i] >= base && i < j) { //�ҵ�֮��Ż��˳�ѭ��
            i++;
        }
        //�����������಻ͬ����
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    //��׼����λ,����i��λ�õ�ֵ�Ϳ�ʼ��׼λ�õ�ֵ����λ��
    arr[left] = arr[i];
    arr[i] = base;
    DownQuickSort(left, i - 1, arr); //��ߵݹ�
    DownQuickSort(i + 1, right, arr); //�ݹ��ұ�
}

void OutPut(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 5, 3, 6, 8, 4, 5, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << len << endl;
    OutPut(arr, len);

    //��������
    UpQuickSort(0, len - 1, arr);
    OutPut(arr, len);

    //��������
    DownQuickSort(0, len - 1, arr);
    OutPut(arr, len);
    return 0;
}

