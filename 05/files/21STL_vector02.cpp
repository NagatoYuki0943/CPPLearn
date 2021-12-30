#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * vector容器中存放自定义数据类型
 */
class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {
    }

    string m_Name;
    int m_Age;
};

void test01() {
    vector<Person> v;
    Person p1("aaa", 60);
    Person p2("bbb", 50);
    Person p3("ccc", 40);
    Person p4("ddd", 30);
    Person p5("eee", 20);

    //添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //遍历数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
        //*it解引用是Person *it是上面的<>中的数据类型
        //cout << "name : " << (*it).m_Name << " age : " << (*it).m_Age << endl;  //name : aaa age : 60 ...
        //直接使用指针效果也一样
        cout << "name : " << it->m_Name << " age : " << it->m_Age << endl;  //name : aaa age : 60 ...
    }
    //另一种写法
    for (auto & it : v) {
        //*it解引用是Person *it是上面的<>中的数据类型
        //cout << "name : " << (*it).m_Name << " age : " << (*it).m_Age << endl;  //name : aaa age : 60 ...
        //直接使用指针效果也一样
        cout << "name : " << it.m_Name << " age : " << it.m_Age << endl;  //name : aaa age : 60 ...
    }
    cout << "----------------------------" << endl;
}

//存放自定的数据类型数据指针
void test02() {
    //Person * 是Person的地址
    vector<Person *> v;
    Person p1("aaa", 60);
    Person p2("bbb", 50);
    Person p3("ccc", 40);
    Person p4("ddd", 30);
    Person p5("eee", 20);

    //添加数据因为存放的是指针,所以要用 &
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //遍历数据  Person *
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); ++it) {
        //*it是上面的<>中的数据类型
        //(*it)是存放的单个Person的指针,就是Person *
        cout << "::name : " << (*it)->m_Name << " age : " << (*it)->m_Age << endl;  //::name : aaa age : 60 ...
    }
}

int main() {
    //test01();
    test02();
    return 0;
}
