#include <iostream>

using namespace std;

/**
 * ��ģ��ͺ���ģ�������
 *      1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ(Clion)����ʵ��
 *      2.��ģ����ģ������б��п�����Ĭ�ϲ���(Clion�к���ģ��Ҳ������Ĭ�ϲ���)
 */


//2.��ģ����ģ������б��п�����Ĭ�ϲ���(Clion�к���ģ��Ҳ������Ĭ�ϲ���)  NameType=string  AgeType=int
template<typename T = int>
T add(T a,T b){
    return a+ b;
}

//2.��ģ����ģ������б��п�����Ĭ�ϲ���(Clion�к���ģ��Ҳ������Ĭ�ϲ���)  NameType=string  AgeType=int
template<class NameType = string, class AgeType = int>
class Person {
public:
    Person(NameType name, AgeType age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "name : " << this->m_Name << endl;
        cout << "age : " << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01() {
    //1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ(Clion)����ʵ��
    Person p1("С��", 15);
    //Person<string, int> p1("С��", 15);
    p1.showPerson();

    int res = add(1,2);
    cout << "res = " << res << endl;
}

int main() {
    test01();
    return 0;
}
