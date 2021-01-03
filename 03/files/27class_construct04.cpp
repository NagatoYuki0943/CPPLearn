#include <iostream>

using namespace std;

/**
 * ǳ����:�򵥵ĸ�ֵ��������(Ĭ�ϵĿ�������),����ָ��,Ȼ�����ͷŵ�ʱ����ͷ�����,���λᱨ��(�Ƿ�����)
 * ���:�ڶ�����������ռ�(�Լ�д�������캯��),���п���,�������ָ��ָ��һ���µ�λ��,�����������ͬ,�Ͳ��ᱨ����(������������ڴ�ռ���и���)
 */

class Person {
public:
    //�޲ι���
    Person() {
        cout << "Ĭ�Ϲ��캯������" << endl;
    }

    //�вι���
    Person(int age, int height) {
        m_Age = age;
        m_Height = new int(height); //�ڶ�����������
        cout << "�вι��캯������" << endl;
    }

    //�Լ�ʵ��һ���������캯��
    Person(const Person &p) {
        cout << "�������캯������" << endl;
        m_Age = p.m_Age;
        //m_Height=p.m_Height; //������Ĭ��ʵ�����д���,������
        //���,��������ռ�
        m_Height = new int(*p.m_Height);  //ע�������,m_Height��һ��ָ��

    }

    //��������
    ~Person() {
        //��������,���������ٵ����ݽ����ͷŲ���
        if (m_Height != NULL) {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "������������" << endl;
    }

    int m_Age;
    int *m_Height; //����ָ��
};

void test01() {
    Person p1(18, 160);
    cout << "p1����:" << p1.m_Age << " p1���:" << *p1.m_Height << endl;

    Person p2(p1);
    cout << "p2����:" << p2.m_Age << " p1���:" << *p2.m_Height << endl;
}

int main() {
    test01();

    system("pause");
    return 0;
}
