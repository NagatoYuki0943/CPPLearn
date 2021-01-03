/**
 * 函数分文件编写
1.创建.h后缀名的头文件
2.创建.cpp后缀名的源文件
3.在头文件中写函数的声明
4.在源文件中写函数的定义
5.在源文件中使用include "头文件"
 */

#include "55swap.h"

using namespace std;

int main() {
    //直接调用55swap中的函数
    int a = 99, b = 100;
    swap(a, b);
    return 0;
}