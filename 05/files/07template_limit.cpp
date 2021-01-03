#include <iostream>
#include <string>

using namespace std;

/**
 * ģ�岻�����ܵ�,��Щ�ض�����������,Ҫʹ�þ��廯�ķ�ʽ������ʵ��
 */
class Person {
public:
    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//�Ա����������Ƿ����
template<typename T>
bool myCompare(T &a, T &b) {
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

//���þ��廯Person�İ汾ʵ�ִ���,�������Ȼ����� template<> ������
//Person�Ƚ�ʱ�����ȵ�����,�����ǵ��������
template<> bool myCompare(Person &p1, Person &p2){
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age){
        return true;
    }else{
        return false;
    }
}


void test01() {
    int a = 10;
    int b = 20;
    bool res = myCompare<int>(a, b);
    if (res) {
        cout << "a ���� b" << endl;
    } else {
        cout << "a ������ b" << endl;
    }
}

void test02() {
    Person P1("С��", 10);
    Person P2("С��", 11);
    bool res = myCompare<Person>(P1, P2);
    if (res) {
        cout << "P1 ���� P2" << endl;
    } else {
        cout << "P1 ������ P2" << endl;
    }
}


int main() {
    test01();
    test02();
    return 0;
}
