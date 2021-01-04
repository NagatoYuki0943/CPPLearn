#include <iostream>
#include <string>

using namespace std;

/**
 * 类模板对象做函数的参数
 *
 * 类模板实例化出的对象,向函数传参的方式
 * 共有三种传入方式:
 *      1.指定传入的类型  ---  直接显示对象的数据类型
 *      2.参数模板化     ---  将对象中的参数变为模板进行传递
 *      3.整个类模板化   ---  将这个对象类型 模板化进行传递
 */
template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "名字:" << this->m_Name << endl;
        cout << "年龄:" << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1.指定传入的类型  ---  直接显示对象的数据类型   Person<string,int> &p
void printPerson1(Person<string, int> &p) {
    p.showPerson();
}

void test01() {
    Person<string, int> p("孙悟空", 500);
    printPerson1(p);
    //名字:孙悟空
    //年龄:500
}

//2.参数模板化     ---  将对象中的参数变为模板进行传递
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    cout << "T1类型: " << typeid(T1).name() << endl;  //T1类型: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    cout << "T2类型: " << typeid(T2).name() << endl;  //T2类型: i
}

void test02() {
    Person<string, int> p("猪八戒", 400);
    printPerson2(p);
    //名字:猪八戒
    //年龄:400
}

//3.整个类模板化   ---  将这个对象类型 模板化进行传递
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T1类型: " << typeid(T).name() << endl;   //T1类型: 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
}

void test03(){
    Person<string, int> p("沙和尚", 300);
    printPerson3(p);
    //名字:沙和尚
    //年龄:300
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
