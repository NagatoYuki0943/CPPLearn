#include <iostream>

using namespace std;
//函数不需要返回值,声明类型可以下void
/*
     * php中函数定义为:
     * function func_name(){
     *       函数体
     *         }
     * c++中不需要关键字,需要写返回值类型
     */

int add(int a, int b) {        //自己定义的函数要放在main函数外面
    int sum = a + b;
    return sum;
}

int main() {

    int num1 = 2, num2 = 3, sum;
    sum = add(num1, num2);
    cout << sum << endl;
    return 0;
}