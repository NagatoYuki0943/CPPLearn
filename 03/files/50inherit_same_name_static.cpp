#include <iostream>

using namespace std;

/**
 * 静态成员和非静态成员出现同名,处理方式一样
 * 静态成员:静态数据:所有对象共享同一份数据;类内声明,类外初始化;编译阶段分配内存
 *        静态成员函数:所有对象共享同一份数据;访问静态成员变量
 *      访问子类同名成员,直接访问即可
 *      访问父类成员,需要加作用域
 *
 *  s.m_A        === Son::m_A        s.func()       == Son::func()         //子类
 *  s.Base::m_A  === Son::Base::m_A  s.Base::func() == Son::Base::func()   //父类
 *                   前一个::是通过类名Son方式访问,第二个::是访问Sase作用域下的m_A
 *
 *  注意:如果子类中出现和父类同名的函数成员函数,子类的同名成员会隐藏掉父类中所有的同名函数(重载函数也会被影藏)
 *      要用Base::方式访问父类中的重载函数
 */
class Base {
public:
    static int m_A;

    static void func() {
        cout << "Base--static void func()" << endl;
    }

    static void func(int a) {
        cout << "Base--static void func(int a)" << endl;
    }
};

//类外初始化
int Base::m_A = 100;

class Son : public Base {
public:
    static int m_A;

    static void func() {
        cout << "Son--static void func()" << endl;
    }

    static void func(int a) {
        cout << "Son--static void func(int a)" << endl;
    }
};

//类外初始化
int Son::m_A = 200;


///同名静态成员属性
void test01() {
    Son s;
    //通过对象访问
    cout << "Son下:\t" << s.m_A << endl;           //200
    cout << "Base下:\t" << s.Base::m_A << endl;    //100
    //通过类名访问
    cout << "Son下:\t" << Son::m_A << endl;        //200
    cout << "Base下:\t" << Son::Base::m_A << endl; //100  前一个::是通过类名Son方式访问,第二个::是访问Sase作用域下的m_A

}

//同名静态函数
void test02() {
    Son s;
    //通过对象访问
    s.func();
    s.Base::func();
    s.Base::func(5);      //访问父类重载函数
    //通过类名访问
    Son::func();
    Son::Base::func();
    Son::Base::func(5);   //访问父类重载函数
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}