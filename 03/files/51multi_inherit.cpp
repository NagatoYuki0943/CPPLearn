#include <iostream>

using namespace std;

/**
 * C++����һ����̳ж����
 * �﷨ class ���� : �̳з�ʽ ����1 , �̳з�ʽ,����2...
 * ��̳п��ܻ�������������ͬ����Ա����,��Ҫ���������������   s1.Base1::m_A     s1.Base2::m_A
 * C++ʵ�ʿ����в�����ʹ�ö�̳�
 */
class Base1 {
public:
    Base1() {
        m_A = 1;
    }

    int m_A;
};

class Base2 {
public:
    Base2() {
        m_A = 21;
        m_B = 2;
    }

    int m_A;
    int m_B;

};

///��̳��﷨
class Son : public Base1, public Base2 {
public:
    Son() {
        m_C = 3;
        m_D = 4;
    }

    int m_C;
    int m_D;
};

void test01() {
    Son s1;
    cout << "sizeof Son=" << sizeof(s1) << endl;  //��������������Լ��ı���֮��
    ///�������г���ͬ����Ա,��Ҫ���������������
    cout << "s1.Base1::m_A=" << s1.Base1::m_A << endl;
    cout << "s1.Base2::m_A=" << s1.Base2::m_A << endl;

}

int main() {
    test01();
    system("pause");
    return 0;
}