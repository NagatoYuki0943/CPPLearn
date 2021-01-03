#include <iostream>

using namespace std;

/**
 * ���캯�����ù���
 * Ĭ�������,c++���������ٸ�һ�������3������
 * 1.Ĭ�Ϲ��캯��(�޲�,������Ϊ��)
 * 2.Ĭ����������(�޲�,������Ϊ��)
 * 3.Ĭ�Ͽ������캯��,�����Խ���ֵ����
 *
 * ���ù���:
 *  ����û������вι��캯��,c++�����ṩĬ���޲ι���,��Ȼ�ṩĬ�Ͽ�������
 *  ����û�����Ĭ�Ͽ�������,c++�����ṩ�������캯��   Person p ����ʹ����
 */
class Person {
public:
    //�޲ι���
    Person() {
        cout << "Person(){}Ĭ�Ϲ��캯������" << endl;
    }

    //�вι���
    Person(int age) {
        m_Age = age;
        cout << "Person(){}�вι��캯������" << endl;
    }

    //��������
    Person(const Person &p) {
        m_Age = p.m_Age;
        cout << "Person(){}�������캯������" << endl;
    }

    //��������
    ~Person() {
        cout << "~Person(){}������������" << endl;
    }

    int m_Age;
};

void test01() {
    Person p;
    p.m_Age = 18;
    Person p2(p);   //��ע��������Ŀ�������֮��,û�����"Person(){}�������캯������",���ǻ����Լ���ֵ����
    cout << "p2����:" << p2.m_Age << endl;
}

///����û������вι��캯��,c++�����ṩĬ���޲ι���,��Ȼ�ṩĬ�Ͽ�������
void test02() {
    Person p(20); //�ڶ������вι���֮��,ע����Ĭ�Ϲ���,������ֱ���½�object�ᱨ��
    Person p2(p);
    cout << "p2����:" << p2.m_Age << endl;
}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
