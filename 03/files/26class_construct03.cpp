#include <iostream>

using namespace std;

/**
 * 构造函数调用规则
 * 默认情况下,c++编译器至少给一个类添加3个函数
 * 1.默认构造函数(无参,函数体为空)
 * 2.默认析构函数(无参,函数体为空)
 * 3.默认拷贝构造函数,对属性进行值拷贝
 *
 * 调用规则:
 *  如果用户定义有参构造函数,c++不再提供默认无参构造,依然提供默认拷贝构造
 *  如果用户定义默认拷贝构造,c++不在提供其他构造函数   Person p 不能使用了
 */
class Person {
public:
    //无参构造
    Person() {
        cout << "Person(){}默认构造函数调用" << endl;
    }

    //有参构造
    Person(int age) {
        m_Age = age;
        cout << "Person(){}有参构造函数调用" << endl;
    }

    //拷贝构造
    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "Person(){}拷贝构造函数调用" << endl;
    }

    //析构函数
    ~Person() {
        cout << "~Person(){}析构函数调用" << endl;
    }

    int m_Age;
};

void test01() {
    Person p;
    p.m_Age = 18;
    Person p2(p);   //在注释了上面的拷贝构造之后,没有输出"Person(){}拷贝构造函数调用",但是还可以继续值拷贝
    cout << "p2年龄:" << p2.m_Age << endl;
}

///如果用户定义有参构造函数,c++不再提供默认无参构造,依然提供默认拷贝构造
void test02() {
    Person p(20); //在定义了有参构造之后,注释了默认构造,再这样直接新建object会报错
    Person p2(p);
    cout << "p2年龄:" << p2.m_Age << endl;
}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
