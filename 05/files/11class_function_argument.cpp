#include <iostream>
#include <string>

using namespace std;

/**
 * ��ģ������������Ĳ���
 *
 * ��ģ��ʵ�������Ķ���,�������εķ�ʽ
 * �������ִ��뷽ʽ:
 *      1.ָ�����������  ---  ֱ����ʾ�������������
 *      2.����ģ�廯     ---  �������еĲ�����Ϊģ����д���
 *      3.������ģ�廯   ---  ������������� ģ�廯���д���
 */
template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "����:" << this->m_Name << endl;
        cout << "����:" << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1.ָ�����������  ---  ֱ����ʾ�������������   Person<string,int> &p
void printPerson1(Person<string, int> &p) {
    p.showPerson();
}

void test01() {
    Person<string, int> p("�����", 500);
    printPerson1(p);
    //����:�����
    //����:500
}

//2.����ģ�廯     ---  �������еĲ�����Ϊģ����д���
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p) {
    p.showPerson();
    cout << "T1����: " << typeid(T1).name() << endl;  //T1����: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    cout << "T2����: " << typeid(T2).name() << endl;  //T2����: i
}

void test02() {
    Person<string, int> p("��˽�", 400);
    printPerson2(p);
    //����:��˽�
    //����:400
}

//3.������ģ�廯   ---  ������������� ģ�廯���д���
template<class T>
void printPerson3(T &p) {
    p.showPerson();
    cout << "T1����: " << typeid(T).name() << endl;   //T1����: 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
}

void test03(){
    Person<string, int> p("ɳ����", 300);
    printPerson3(p);
    //����:ɳ����
    //����:300
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
