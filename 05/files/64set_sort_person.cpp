#include <iostream>
#include <set>
#include <string>

using namespace std;

/**
 * set存放自定义数据类型
 *
 */
class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;

};

class comparePerson{
public:
    bool operator()(const Person &p1,const Person &p2){
        //按照年龄降序
        return p1.m_Age > p1.m_Age;
    }
};

void test01(){
    set<Person,comparePerson> s;
    Person p1("A", 23);
    Person p2("B", 27);
    Person p3("C", 25);
    Person p4("D", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person,comparePerson>::iterator i =s.begin(); i != s.end() ; ++i) {
        cout << "name is " << i->m_Name << ", age is " << i->m_Age << endl;
    }
}

int main() {
    test01();
    return 0;
}
