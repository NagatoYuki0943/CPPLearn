#include <iostream>

using namespace std;

int main() {
    //数组元素首尾调换,下标互换
    int arr1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    int start = 0;
    int tmp;
    int end = sizeof(arr1) / sizeof(arr1[0]) - 1;    //20/4-1=4
    while (start < end) {      //首尾互换,start++,end--;直到start=end
        tmp = arr1[start];
        arr1[start] = arr1[end];
        arr1[end] = tmp;
        start++;
        end--;
    }
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    return 0;
}