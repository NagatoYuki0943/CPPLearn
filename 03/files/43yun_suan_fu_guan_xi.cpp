#include <iostream>

using namespace std;

/**
 * ���ع�ϵ�����,> >= < <= ��Ҫ��== !=
 * ֧�ֳ�Ա������ȫ�ֺ���д��
 */

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {}

    string m_Name;
    int m_Age;
    /*//����==
    bool operator==(Person &p){
        if (this->m_Name==p.m_Name && this->m_Age==p.m_Age){
            return true;
        }else{
            return false;
        }
    }*/
    /*bool operator!=(Person &p){
        if (this->m_Name==p.m_Name && this->m_Age==p.m_Age){
            return false;
        }else{
            return true;
        }
    }*/
};

//ȫ�ֺ�������,����
bool operator==(Person &p1, Person &p2) {
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(Person &p1, Person &p2) {
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age) {
        return false;
    } else {
        return true;
    }
}

void test01() {
    Person p1("tom", 18);
    Person p2("tom", 18);
    Person p3("jerry", 16);
    if (p1 == p2) {  //����==����
        cout << "p1��p2���" << endl;
    } else {
        cout << "p1��p2�����" << endl;
    }
    if (p1 != p3) {  //����!=����
        cout << "p1��p3�����" << endl;
    } else {
        cout << "p1��p3���" << endl;
    }
}

int main() {
    test01();
    system("pause");
    return 0;
}
