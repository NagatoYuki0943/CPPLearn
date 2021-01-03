#include <iostream>

using namespace std;

/**
 * 类模板和函数模板的区别
 *      1.类模板没有自动类型推导的使用方式(Clion)可以实现
 *      2.类模板在模板参数列表中可以有默认参数(Clion中函数模板也可以有默认参数)
 */


//2.类模板在模板参数列表中可以有默认参数(Clion中函数模板也可以有默认参数)  NameType=string  AgeType=int
template<typename T = int>
T add(T a,T b){
    return a+ b;
}

//2.类模板在模板参数列表中可以有默认参数(Clion中函数模板也可以有默认参数)  NameType=string  AgeType=int
template<class NameType = string, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name : " << this->m_Name << endl;
        cout << "age : " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01() {
    //1.类模板没有自动类型推导的使用方式(Clion)可以实现
    Person p1("小红", 15);
    //Person<string, int> p1("小红", 15);
    p1.showPerson();

    int res = add(1,2);
    cout << "res = " << res << endl;
}

int main() {
    test01();
    return 0;
}
