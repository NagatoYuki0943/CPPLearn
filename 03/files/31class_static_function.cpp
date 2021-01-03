#include <iostream>

using namespace std;

/**
 * 静态成员变量:
 *      所有对象共享同一份数据   静态成员不属于某个对象上,所有对象共享同一份数据
 *      在编译阶段分配内存:全局区
 *      类内声明,类外初始化,必须有初始值,不能定义的时候赋值,会报错,必须在外面   声明:static int m_A;    初始化:int Person::m_A=100;
 *   静态成员变量也有访问权限:公共在类外可以访问,私有权限在类外不能访问
 * 静态成员函数:
 *      所有对象共享同一个函数
 *      静态成员函数只能访问静态成员变量,因为非静态变量只有通过对象访问,而静态成员函数不知道去访问哪一个object的变量
 *   静态成员函数也有访问权限:公共在类外可以访问,私有权限在类外不能访问
 */

class Person {
public:
    //静态成员函数
    static void func() {
        m_A = 100;  //静态函数可以访问静态变量
        //m_B=99; //会报错,静态函数不能访问费静态变量
        cout << "static void func()调用" << endl;
    }

    static int m_A;
    int m_B = 0;
private:
    static void func1() {
        cout << "static void func1()调用" << endl;
    }
};

int Person::m_A = 10;

void test01() {
    //1.通过对象来访问
    Person p;
    p.func();
    //p.func1();        //不能调用,是私有的
    //2.通过类名来访问
    Person::func();
    //Person::func1();  //不能调用,是私有的

}

int main() {
    test01();

    system("pause");
    return 0;
}
