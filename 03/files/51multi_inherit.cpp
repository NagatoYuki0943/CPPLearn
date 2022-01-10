#include <iostream>

using namespace std;

/**
 * C++允许一个类继承多个类
 * 语法 class 子类 : 继承方式 父类1 , 继承方式,父类2...
 * 多继承可能会引发父类中有同名成员出现,需要加作用域加以区分   s1.Base1::m_A     s1.Base2::m_A
 * C++实际开发中不建议使用多继承
 */
class Base1 {
public:
    Base1() {
        m_A = 1;
    }

    int m_A;
};

class Base2 {
public:
    Base2() {
        m_A = 21;
        m_B = 2;
    }

    int m_A;
    int m_B;

};

///多继承语法
class Son : public Base1, public Base2 {
public:
    Son() {
        m_C = 3;
        m_D = 4;
    }

    int m_C;
    int m_D;
};

void test01() {
    Son s1;
    cout << "sizeof Son=" << sizeof(s1) << endl;  //包含两个父类和自己的变量之和
    ///当父类中出现同名成员,需要加作用域加以区分
    cout << "s1.Base1::m_A=" << s1.Base1::m_A << endl;
    cout << "s1.Base2::m_A=" << s1.Base2::m_A << endl;

}

int main() {
    test01();
    system("pause");
    return 0;
}