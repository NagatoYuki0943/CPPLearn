#include <iostream>

using namespace std;

int main() {
    //数组名是常量,不能重新赋值
    //一位数组名可以统计整个数组再内存中的长度
    //可以获取数组再内存中的首地址
    int arr[5] = {1, 2, 3, 4, 5};
    int length1 = sizeof(arr);      //统计数组长度
    int length2 = sizeof(arr[0]);   //统计数组第一个数据长度
    cout << "数组长度为:" << length1 << " 第一个数据长度为: " << length2 << endl;   //20 4 int一个长度为4   20/4=5个
    cout << "数组内存首地址为:" << arr << endl;          //数组在内存中的首地址
    cout << "数组中第一个元素地址为:" << &arr[0] << endl; //&:取地址符
    cout << "数组中第二个元素地址为:" << &arr[1] << endl; //&:取地址符  和arr[0]差4个字节
    return 0;
}
