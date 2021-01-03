#include <iostream>

using namespace std;

void BubbleSort(int *arr, int len) {
    //升序
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    cout << "升序排列:";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //降序
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {   //j=每次排列最后的下标
            if (arr[j] > arr[j - 1]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    cout << "降序排列:";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 2, 3, 3, 4, 5, 8, 8, 6, 6, 7, 7, 5, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    //cout << len << endl;

    cout << "开始排列:";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr, len);

    cout << "结束排列:";    //使用指针传递之后,原数组也会发生改变
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}