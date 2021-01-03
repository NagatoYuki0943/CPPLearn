#include <iostream>

using namespace std;

int main() {
    //冒泡排序,升序
    int arr[] = {1, 58, 6, 2, 4, 5, 4, 265, 45};
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    int i, j;
    //打印原序列
    for (i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (i = end; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {  //注意这是升序排列,每次排完最后一个就是最大的了,
                int tmp;     //不能把大于号直接换成小于号当做降序排列,因为降序排列后第一个为最大的,不用再排列了
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //降序
    for (i = end; i > 0; i--) {
        for (j = end; j > (end - i); j--) {
            if (arr[j] > arr[j - 1]) {
                int tmp;
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
    for (i = 0; i <= end; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}