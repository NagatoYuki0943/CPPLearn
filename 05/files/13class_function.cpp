#include <iostream>
#include <string>
using namespace std;
/**
 * ��ģ���Ա��������ʵ��
 *  
 */
template<class T1,class T2>
class Person{
public:
    Person(T1 name,T2 age);
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }

    void showPerson();
//    {
//        cout << "����: " << this->m_Name << " ����: " << this->m_Age << endl;
//    }

    T1 m_Name;
    T2 m_Age;
};

//���캯������ʵ��
template<class T1,class T2>
//Ҫ˵��Person��ģ���� Person<T1,T2>
Person<T1,T2>::Person(T1 name,T2 age){
    this->m_Name = name;
    this->m_Age = age;
}

//��Ա��������ʵ��
template<class T1,class T2>
//Ҫ˵��Person��ģ���� Person<T1,T2>
void Person<T1,T2>::showPerson() {
    cout << "����: " << this->m_Name << " ����: " << this->m_Age << endl;
}

void test01(){
    Person<string, int> p1("����",99);
    p1.showPerson();    //����: ���� ����: 99
}

int main() {
    test01();
    return 0;
}
