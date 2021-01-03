#include <iostream>

using namespace std;

//交换模板
template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//排序模板
template<typename T>
//从大到小选择排序
void downSort(T arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        //认定第一个为最大值
        int max = i;
        for (int j = i + 1; j < len; j++) {
            //认定的最大值小于遍历出的最大值
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        //交换 max 和 i 的下标
        if (max != i) {
            mySwap<T>(arr[max], arr[i]);
        }
    }
}

//打印数组模板
template<typename T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void test01() {
    char charArr[]{'a', 'c', 'd', 'v', 'r', 'c', 'x'};
    int len = sizeof(charArr) / sizeof(char);
    downSort(charArr, len);
    printArray(charArr, len);

    int intArr[]{5, 12, 4, 68, 6, 3, 1, 2, 1};
    len = sizeof(intArr) / sizeof(int);
    downSort(intArr, len);
    printArray(intArr, len);
}


int main() {
    test01();
    system("pause");
    return 0;
}
