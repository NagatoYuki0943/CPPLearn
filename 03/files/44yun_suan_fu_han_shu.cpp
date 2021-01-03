#include <iostream>
#include <string>

using namespace std;

/**
 * 函数调用运算符()也可以重载,让类可以像函数一样使用
 * 由于重载后使用的方式非常像函数,因此成为防函数
 * 仿函数没有固定写法,非常灵活
 * 在类内使用
 *
 * 使用方式
 *  class MyPrint{}  --->>>   myPrint("hello world");
 * 使用匿名函数对象  MyAdd()是匿名对象,后面是赋值
     cout << "100 + 100" << MyAdd()(100,100) << endl;
 */
class MyPrint {
public:
    //重载函数调用运算符
    void operator()(string test) {
        cout << test << endl;
    }
};

void MyPrint02(string test) {
    cout << test << endl;
}

///仿函数没有固定写法,非常灵活
//加法类
class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

void test01() {
    MyPrint myPrint;
    myPrint("hello world");  //传给了内部的operator(),由于重载后使用的方式非常像函数,因此成为防函数
    MyPrint02("hello world");//普通函数
}

void test02() {
    //int a=MyAdd add(10,20);   //不能创建时就调用,会出错
    MyAdd add;
    int a = add(10, 20);
    cout << "a=" << a << endl;

    ///匿名函数对象  MyAdd()是匿名对象,后面是赋值
    cout << "100+100=" << MyAdd()(100, 100) << endl;
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}