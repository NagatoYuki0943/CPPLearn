#include <iostream>

using namespace std;

/**
 * 引用可以作为函数返回值
 * 不要返回局部变量的引用,使用静态变量
 * 函数的调用可以作为左值,函数返回的是引用的变量,可以直接更改里面的值
 */
int test00() {
    int a = 10;//存放在栈区
    return a;
}
//不要返回局部变量的引用,使用静态变量
/*int& test01(){
    int a=10;//存放在栈区
    return a;//返回局部变量的引用
}*/
int &test02() {
    static int a = 11; //静态变量,存放在全局区
    return a;
}


int main() {
    cout << "test00->a=" << test00() << endl; //这样直接输出a的值,即使a已经不存在了

    /*int &ref1=test01();  //ref是test01中的别名
    cout << ref1 << endl;//无法正常输出,vs中第一次可以输出,第二次结果错误*/

    int &ref2 = test02();
    cout << "ref2=" << ref2 << endl;//正常输出

    //函数的引用作为左值,函数返回的是引用的变量,可以直接更改里面的值
    test02() = 100;
    cout << "ref2=" << ref2 << endl;//正常输出


    system("pause");
    return 0;
}
