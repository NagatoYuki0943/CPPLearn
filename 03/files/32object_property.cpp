#include <iostream>

using namespace std;

/**
 * 成员变量和成员函数分开存储
 * c++中,类内的成员变量和成员函数分开存储
 * 只有非静态成员变量才属于类的对象上(静态的成员变量和函数不属于任何object)
 */
class Person {
    int m_A;              //非静态成员变量     属于类的对象上
    static int m_B;       //静态成员变量      不属于类的对象上
    void func() {}         //非静态成员函数     不属于类的对象上
    static void func1() {} //静态成员函数      不属于类的对象上
};

int Person::m_B = 10;


void test01() { //空对象测试
    Person p;
    //空对象占用内存空间是 1
    //c++编译器会给每个对象也分配一个字节空间,是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "sizeof(p)=" << sizeof(p) << endl;  //空的类占1
}

void test02() {  //非空对象测试
    Person p;
    //空对象占用内存空间是 4,int占了4个字节
    //说明非静态变量属于object,而静态成员变量,非静态成员函数不属于object
    cout << "sizeof(p)=" << sizeof(p) << endl;  //空的类占1
}


int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
