#include <iostream>

using namespace std;
///ѡ������
/**
 *����Ϊ��һ������С�Ļ�������,����һ����ʼ��,����ҵ��ȵ�һ��С�Ļ��ߴ��,��������λ��
 */

//���
void OutPut(int a[], int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//����
void UpSort(int a[], int len) {
    cout << "��������" << endl;
    int min;
    for (int i = 0; i < len - 1; i++) {   // i��0��ʼ,��С��len-1����
        min = i;
        for (int j = i + 1; j < len; j++) { //j��i+1��ʼ,��len-1����
            if (a[min] > a[j]) {        //�ͽ���Ψһ������
                min = j;
            }
        }
        if (min != i) {
            int tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }
    OutPut(a, len);
}

//����
void DownSort(int a[], int len) {
    cout << "��������" << endl;
    int max;
    for (int i = 0; i < len - 1; i++) {    // i��0��ʼ,��С��len-1����
        max = i;
        for (int j = i + 1; j < len; j++) {  //j��i+1��ʼ,��len-1����
            if (a[max] < a[j]) {         //������Ψһ������
                max = j;
            }
        }
        if (max != i) {
            int tmp = a[max];
            a[max] = a[i];
            a[i] = tmp;
        }
    }
    OutPut(a, len);
}

int main() {
    int arr[] = {9, 8, 3, 2, 1, 7, 0, 6, 5, 4, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    OutPut(arr, len);
    UpSort(arr, len);
    DownSort(arr, len);
    //OutPut(a);
    return 0;
}
