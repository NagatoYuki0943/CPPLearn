#include <iostream>

using namespace std;

/**
 * 函数模板: 通过建立一个通用函数,其函数返回值类型和形参类型可以不具体指定,用一个虚拟的类型来代表
 *  template<typename T>
 *  template --- 声明创建模板
 *  typename --- 表明其后面的符号是一种数据类型,可以用class代替
 *  T        --- 通过的数据类型,名称可以替换,通常为大写字母
 *
 *  使用:
 *      1.自动类型推导
 *      mySwap(a,b);
 *      2.显示声明类型
 *      mySwap<int>(c,d);
 */

//后面跟着函数说明是函数模板
template<typename T>
//返回值可以使T,,没有返回值是void
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 1,b = 2;
    //函数模板有两种使用方法
    //1.自动类型推导
    mySwap(a,b);
    cout << a << endl;
    cout << b << endl;


    //2.显示声明类型
    int c = 3,d = 4;
    mySwap<int>(c,d);
    cout << c << endl;
    cout << d << endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}