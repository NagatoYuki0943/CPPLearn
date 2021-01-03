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
    //静态成员变量,所有对象都共享同一份数据
    //编一阶段分配内存(全局)
    //类内声明,类外初始化
    static int m_A;
private:
    //静态成员变量也有访问权限
    static int m_B;
};

//类外初始化
int Person::m_A = 100;
int Person::m_B = 50;


void test01() {
    Person p;
    cout << p.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl; //p2改了,用p去访问,数据变为200,说明数据被所有对象共享
};

void test02() {
    ///静态成员不属于某个对象上,所有对象共享同一份数据
    ///因此,静态成员变量有两种访问方式
    //1.通过对象调用
    Person p;
    cout << p.m_A << endl;
    //2.通过类名进行访问
    cout << Person::m_A << endl;
    //cout << Person::m_B << endl;  //会报错,类外不能访问
}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
