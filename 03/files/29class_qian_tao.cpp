#include <iostream>
#include <string>

using namespace std;

/**
 * c++�еĳ�Ա����ʹ��һ�����еĶ���,��Ϊ�����Ա
 * �ȹ���������class,�����Լ���class    �ȹ���Phone,�󹹽�person    ���ں���
 * ���ͷ��Լ���class,���ͷ�������class    ������Person,������Phone    �������
 */
class Phone {
    //����
public:
    Phone(string pName) : m_PName(pName) {
        cout << "Phone�Ĺ��캯������" << endl;
    }

    ~Phone() {
        cout << "Phone��������������" << endl;
    }

    //Ʒ��
    string m_PName;


};

class Person {
public:
    Person(string name, string pName) : m_Name(name), m_Phone(pName) { //�����൱�� Phone m_Phone=pName ��ʽת����
        cout << "Person�Ĺ��캯������" << endl;
    }

    ~Person() {
        cout << "Person��������������" << endl;
    }

    //����
    string m_Name;
    //�ֻ�
    Phone m_Phone;
};

void test01() {
    Person p("С��", "ƻ��");
    cout << p.m_Name << "����" << p.m_Phone.m_PName << "�ֻ�" << endl;

}

int main() {
    test01();

    system("pause");
    return 0;
}
