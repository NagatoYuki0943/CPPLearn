#include <iostream>

using namespace std;

/**
指针
1.定义一个指向int型的指针。
int *p;

2.定义一个指向Int的指针的数组。
int *p[10];

3.定义一个指向一个int的数组的指针。
int (*p)[10];

4.定义一个函数指针，函数的参数为Int,返回值为Int
int (*p)(int);

5.定义一个函数指针，参数为int,返回值是一个指针，指向一个Int的数组
int (*(*p)(int))[10];

6.一个有十个指针的数组，每个指针指向一个函数，该函数有一个整形参数和一个整型的返回值
int (*p[10])(int);
*/

int main() {
    //1.定义指针,就是内存地址
    //指针在32位操作系统占用4字节空间
    //指针在64位操作系统占用8字节空间
    int a = 10;
    //指针定义的方法:  数据类型 * 指针变量名
    int *p;
    //指针记录变量a的地址
    p = &a;
    cout << "a的地址是" << &a << endl;
    cout << "指针p=" << p << endl;

    //2.使用指针,可以通过解引用的方式来找到指针指向的内存  *p
    // 指针前加 * 代表解引用,找到指针指向的内存中的数据
    *p = 1000;  //a也等于1000
    cout << "*p=" << *p << endl;
    cout << "a=" << a << endl;

    //指针在32位操作系统占用4字节空间
    //指针在64位操作系统占用8字节空间
    cout << "指针所占内存大小为:" << sizeof(p) << endl;       //不论 * 是什么类型,长度都是8个字节
    cout << "sizeof(int *)=" << sizeof(int *) << endl;
    cout << "sizeof(float *)=" << sizeof(float *) << endl;
    cout << "sizeof(double *)=" << sizeof(double *) << endl;
    cout << "sizeof(string *)=" << sizeof(string *) << endl;


    return 0;
}