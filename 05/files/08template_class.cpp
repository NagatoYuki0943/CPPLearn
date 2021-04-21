#include <iostream>
#include <string>
using namespace std;
/**
 * 创建一个通用类,类中成员数据类型不具体指定,用一个虚拟的类型来代表
 * template<class T>
 * 这一行是函数就是函数模板,是类就是类模板
 */

//一个模板设置多个类型
template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << "name = " << this->m_Name << endl;
        cout << "age = " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01() {
    //多个模板类型使用方式
    Person<string, int> p1("孙悟空", 999);
    p1.showPerson();
}

int main() {
    test01();
    return 0;
}
