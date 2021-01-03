#include <iostream>

using namespace std;

int main() {
    /**
     * 空指针:指针变量指向内存中编号为0的空间   0-255编号的内存是系统占用的,不能访问
     * 用途:初始化指针变量
     * 注意:空指针指向的内存是不可访问的
     */
    int *p1 = NULL;
    //*p1=100;  //不能访问

    /**
     * 野指针:指针指向非法的内存空间
     * 如没有分配的内存空间   如:任意的0x1100
     */
    int *p2 = (int *) 0x1100;
    //尝试访问
    cout << p2 << endl;
    cout << *p2 << endl;  //不会输出

    return 0;
}