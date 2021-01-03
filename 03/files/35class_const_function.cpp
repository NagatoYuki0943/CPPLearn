#include <iostream>

using namespace std;

/**
 * const 常量  static 静态
 * const修饰成员函数
 *  常函数:
 *      成员函数后加const我们称为这个函数为常函数      void showPerson () const {}
 *      常函数不可以修改成员函数
 *      成员属性声明时加关键字mutable后,在常函数中依然可以修改   mutable int m_B;
 *  常对象:
 *      声明对象前加const称该对象为常对象
 *      常对象只能调用常函数,不能修改变量
 *      成员属性声明时加关键字mutable后,在对象中也依然可以修改   mutable int m_B;
 */
class Person {
public:
    //常函数
    /**
     * this指针的本质是指针常量,指针的指向是不可以修改的
     * Person * const this;
     * this=NULL; //this指针不可以修改指针的指向
     * const Person * const this; === void showPerson () const{}
     * const 修饰的是this指向,让指针指向的值也不可以修改==常函数
     */

    void showPerson() const {
        //m_A=100; //这样就不能修改了普通变量了
        m_B = 100;
    }

    void func() {
        m_A = 1000;
    }

    int m_A;
    mutable int m_B; //特殊变量,即使在常函数中也可以修改这个值     成员属性声明时加关键字mutable后,在常函数中依然可以修改
};

void test01() {
    Person p;
    p.showPerson();
};

//常对象
void test02() {
    const Person p{}; //在对象前加const,变为常对象
    //p.m_A=100;    //会报错,不能修改
    p.m_B = 110;      //mutable 也可以修改

    //常对象只能调用常函数
    p.showPerson(); //可以调用常函数
    //p.func();     //会报错,普通函数可能修改变量,但是常对象不能修改,因此不能调用
}

int main() {


    system("pause");
    return 0;
}
