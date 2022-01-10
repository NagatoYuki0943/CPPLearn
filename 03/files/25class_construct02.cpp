#include <iostream>

using namespace std;

/**
 * 拷贝构造函数调用时机
 *  1.使用一个已经创建完毕的对象来初始化一个新对象
 *  2.值传递的方式给函数参数传值
 *  3.以值方式返回局部变量
 */
class Person {
public:
    //无参构造
    Person() {
        cout << "Person(){}无参构造函数调用" << endl;
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

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
    Person p1(20);
    Person p2(p1);
    cout << "p2的年龄:" << p2.m_Age << endl;
}

//2.值传递的方式给函数参数传值
void doWork(Person p) {  //值传递

}

void test02() {
    Person p; //无参构造
    doWork(p);//调用拷贝构造函数,实参传给形参的时候调用拷贝构造
}

//3.以值方式返回局部变量
Person doWork2() {
    Person p1;
    cout << (long long) &p1 << endl;
    return p1;  //应该返回的是值,会拷贝p1返回新值,但是clion中两个地址相同
}

void test03() {
    Person p = doWork2();
    cout << (long long) &p << endl;
}


int main() {
    //test01();
    //test02();
    test03();


    system("pause");
    return 0;
}
