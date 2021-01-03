#include <iostream>

using namespace std;
/**
 * 引用作为重载条件
 * 函数重载碰到默认参数
 */

//引用作为重载条件 int和const int类型不同
void func(int &m) { //int &m=10,不合法,不能传递进来
    cout << "(int &m)的调用" << endl;
}

void func(const int &m) { //const int &m=10->tmp=10;const int &m=tmp;
    cout << "(const int &m)的调用" << endl;
}

//函数重载碰到默认参数
void func2(int a) {
    cout << "func2(int a,int b)的调用" << endl;
}

void func2(int a, int b = 10) {
    cout << "func2(int a,int b=10)的调用" << endl;
}

int main() {
    int a = 10;   //变量传入会传入不加const的
    func(a); //无const的

    //直接传入常量会走const
    func(10);//有const的

    //func2(a);//当函数碰到默认参数,会出现二义性,报错,尽量避免这种情况
    int b = 5;
    func2(a, b); //两个参数没有问题


    system("pause");
    return 0;
}
