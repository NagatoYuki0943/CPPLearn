#include <iostream>

using namespace std;
/**
 * 访问子类同名成员,直接访问即可
 * 访问父类同名成员,需要加作用域
 *      class Son
 *      class Son : public Base
 *      通过子类对象访问父类中同名成员属性  s1.Base::m_A
 *      通过子类对象调用父类同名函数       s2.Base::func();
 *      调用父类中的重载函数              s2.Base::func(10);
 *   如果子类中出现和父类同名的函数成员函数,子类的同名成员会隐藏掉父类中所有的同名函数(重载函数也会被影藏)
 *   要用Base::方式访问父类中的重载函数
 */

/**
 * 注意
 * (1)  PHP没有同名函数,所以子类出现同名函数就是重写,C++和C#出现同名函数算是隐藏,使用了virtual或abstract才是重写
 *      PHP子类方法重写父类方法不能比父类更严格,即父类方法如果是public,子类方法必须是public;父类方法如果是protected,子类方法可以使public或protected
 *      C++中没有这条规则
 *      C#使用virtual/abstract和override重写时不能修改访问修饰符
 *
 * (2)  PHP7要求被重写的方法必须与父类保持参数一致(数量和类型)
 *      C++中没有这条规则
 *      C#使用virtual/abstract和override重写时也要参数一致(数量和类型),不是重写就没问题
 *      C#使用覆盖不是重写,(父类无参数,子类有参数)不给参数调用父类方法,给参数调用子类方法
 *
 *  php使用 parent::父类方法() 调用父类方法,无论静态,动态都使用parent::
 */

class Base {
public:
    Base() {
        m_A = 100;
    }

    void func() {
        cout << "Base - func()调用" << endl;
    }

    //发生函数重载
    void func(int a) {
        cout << "Base - func(int a)调用" << endl;
    }

    int m_A;
};

class Son : public Base {
public:
    Son() {
        m_A = 200;
    }

    void func() {
        cout << "Son - func()调用" << endl;
    }

    int m_A;
};

//同名成员属性处理方式
void test01() {
    Son s1;
    cout << "m_A=" << s1.m_A << endl;         //默认打印子类自身的属性
    cout << "Son-m_A=" << s1.Base::m_A << endl;//父类作用域  s1.Base::m_A
}

//同名成员函数函数处理方式
void test02() {
    Son s2;
    s2.func();           //默认调用子类函数
    s2.Base::func();     //使用父类作用域调用父类func()
    ///如果子类中出现和父类同名的函数成员函数,子类的同名成员会隐藏掉父类中所有的同名函数(重载函数也会被隐藏)
    ///要用Base::方式访问父类中的重载函数
    s2.Base::func(10);
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}



