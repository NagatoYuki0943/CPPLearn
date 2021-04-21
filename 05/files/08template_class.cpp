#include <iostream>
#include <string>
using namespace std;
/**
 * ����һ��ͨ����,���г�Ա�������Ͳ�����ָ��,��һ�����������������
 * template<class T>
 * ��һ���Ǻ������Ǻ���ģ��,���������ģ��
 */

//һ��ģ�����ö������
template<class NameType, class AgeType>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << "name = " << this->m_Name << endl;
        cout << "age = " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01() {
    //���ģ������ʹ�÷�ʽ
    Person<string, int> p1("�����", 999);
    p1.showPerson();
}

int main() {
    test01();
    return 0;
}
