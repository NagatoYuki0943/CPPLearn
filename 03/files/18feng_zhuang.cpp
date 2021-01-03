#include <iostream>

using namespace std;

/**
 * public    :公共权限  成员 类内可以访问 类外可以访问
 * protected :保护权限  成员 类内可以访问 类外不可以访问 子类可以访问
 * private   :私有权限  成员 类内可以访问 类外不可以访问 子类不可以访问
 * 类内声明，类外实现时，不需要在外面用public等修饰，用自己的类型修饰
 */

class Person {

    //public
public:
    string m_Name;
protected:
    string m_car;
private:
    int m_pass;
public:
    void func() {  //类内可以访问
        m_Name = "张三";
        m_car = "火车";
        m_pass = 123456;
    }
};

int main() {
    //实例化
    Person p1;
    p1.m_Name = "李四";
//    p1.m_car="奔驰"; //这两行都会报错,不能访问
//    p1.m_pass=123;
    p1.func(); //可以访问



    system("pause");
    return 0;
}
