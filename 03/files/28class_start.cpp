#include <iostream>

using namespace std;

/**
 * c++�ṩ�˳�ʼ���б��﷨,����ʼ������
 * �﷨: ���캯��():����1(ֵ1),����2(ֵ2),����3(ֵ3)...{}
 *   Person(int a,int b,int c):m_A(a),m_B(b),m_C(c){}
 */

class Person {
public:
    //��ͳ��ʼ������
    /*Person(int a,int b,int c){
        m_A=a;
        m_B=b;
        m_C=c;
    }*/

    //��ʼ���б�
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
