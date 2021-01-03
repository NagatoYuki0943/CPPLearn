#include <iostream>

using namespace std;

//函数可以声明多次,但只能定义一次
int function_max(int a, int b);    //提前声明,告诉主函数它是存在的,函数写在main函数下面,不提前声明会看不到


int main() {
    int num1 = 4, num2 = 5, max;
    max = function_max(num1, num2);
    cout << max << endl;

    return 0;
}


int function_max(int a, int b) {
    return a >= b ? a : b;
}