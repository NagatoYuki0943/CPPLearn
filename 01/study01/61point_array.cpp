#include <iostream>

using namespace std;

int main() {
    //利用指针访问数组中的元素
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "第一个元素是:" << arr[0] << endl;

    int *p = arr;   //不用取地址符号,arr就是数组的首地址
    cout << &arr << endl; //首地址
    cout << p << endl;    //首地址
    cout << *p << endl;   //第一个元素
    p++;//让指针向后偏移4个字节
    //cout << sizeof(p) << endl; 这里占8个字节,但是也可以移到下一个数据,而不是移动两个
    cout << *p << endl;

    int *p2 = arr;
    for (int i = 1; i < 10; i++) {
        cout << *p2 << " ";
        p2++;
    }
    return 0;
}