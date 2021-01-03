#include "55swap.h"    //适应#include "" 包含头文件

//函数定义
void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
    cout << "a=" << a << " b=" << b << endl;
}

