#include <iostream>

using namespace std;

/**
 * 重载关系运算符,> >= < <= 主要是== !=
 * 支持成员函数和全局函数写法
 */

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {}

    string m_Name;
    int m_Age;
    /*//重载==
    bool operator==(Person &p){
        if (this->m_Name==p.m_Name && this->m_Age==p.m_Age){
            return true;
        }else{
            return false;
        }
    }*/
    /*bool operator!=(Person &p){
        if (this->m_Name==p.m_Name && this->m_Age==p.m_Age){
            return false;
        }else{
            return true;
        }
    }*/
};

//全局函数重载,可以
bool operator==(Person &p1, Person &p2) {
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(Person &p1, Person &p2) {
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
        return false;
    } else {
        return true;
    }
}

void test01() {
    Person p1("tom", 18);
    Person p2("tom", 18);
    Person p3("jerry", 16);
    if (p1 == p2) {  //调用==重载
        cout << "p1和p2相等" << endl;
    } else {
        cout << "p1和p2不相等" << endl;
    }
    if (p1 != p3) {  //调用!=重载
        cout << "p1和p3不相等" << endl;
    } else {
        cout << "p1和p3相等" << endl;
    }
}

int main() {
    test01();
    system("pause");
    return 0;
}
