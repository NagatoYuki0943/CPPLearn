#include <iostream>
#include <string>
using namespace std;
//�����ʽ1:ֱ�Ӱ��� .cpp   �� #include "14Person.h" ��Ϊ #include "14Person.cpp"  ������
//#include "14Person.cpp"

//�����ʽ2: ��������ʵ��д��һ���ļ���,�����ĺ�׺���� .hpp hpp��Լ��������,������ǿ��       ����
#include "14Person.hpp"
/**
 * ����:
 *      ��ģ���г�Ա��������ʱ�����ڵ��ý׶�,���·��ļ���дʱ���Ӳ���
 * ���:
 *      �����ʽ1:ֱ�Ӱ��� .cpp
 *          �� #include "14Person.h" ��Ϊ #include "14Person.cpp"
 *          ע��,Դ�ļ����� .cpp,��������ʱ������
 *          ������
 *      �����ʽ2: ��������ʵ��д��һ���ļ���,�����ĺ�׺���� .hpp hpp��Լ��������,������ǿ��
 *      �ŵ�һ��
 *          ����
 */

//template<class T1, class T2>
//class Person {
//public:
//    Person(T1 name, T2 age);
//
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//    cout << "����:" << this->m_Name << " ����:" << this->m_Age << endl;
//}


void test01(){
    Person<string, int> p("С��",17);
    p.showPerson();
}

int main() {
    test01();
    return 0;
}
