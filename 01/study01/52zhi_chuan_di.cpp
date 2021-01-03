#include <iostream>

using namespace std;

//值传递的时候,形参发生变化不影响实际参数,也就是说在函数里面的形式参数交换了,实际参数不会发生改变,因为内存地址不同,形式参数改变没有影响实际参数
//函数不需要返回值,声明类型可以下void
//函数
void function_swap(int num1, int num2) {
    cout << "function_交换后:" << num1 << " " << num2 << endl;

    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
    cout << "function_交换后:" << num1 << " " << num2 << endl;
}

int main() {
    int a = 5, b = 6;
    cout << a << " " << b << endl;
    function_swap(a, b);
    //值传递的时候,形参发生变化不影响实际参数
    cout << a << " " << b << endl;  //和上面输出一样
    return 0;
}