#include <iostream>

using namespace std;

/**
 * c++提供了初始化列表语法,来初始化属性
 * 语法: 构造函数():属性1(值1),属性2(值2),属性3(值3)...{}
 *   Person(int a,int b,int c):m_A(a),m_B(b),m_C(c){}
 */

class Person {
public:
    //传统初始化操作
    /*Person(int a,int b,int c){
        m_A=a;
        m_B=b;
        m_C=c;
    }*/

    //初始化列表
    Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {}

    int m_A;
    int m_B;
    int m_C;

};

void test01() {
    Person p(10, 20, 30);

    cout << "m_A=" << p.m_A << " m_B=" << p.m_B << " m_C=" << p.m_C << endl;
}


int main() {
    test01();

    system("pause");
    return 0;
}
