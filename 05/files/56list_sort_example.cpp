#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
 * 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
 */
class Person {
public:
    Person(string name, int age, int height, int weight) : m_Name(name), m_Age(age), m_Height(height),
                                                           m_Weight(weight) {

    }

    string m_Name;
    int m_Age;
    int m_Height;
    int m_Weight;
};

void printList() {

}

void printList(const list<Person> &L) {
    for (list<Person>::const_iterator i = L.begin(); i != L.end(); ++i) {
        //迭代器类似于指针
        cout << "Name is " << i->m_Name << ", age is " << i->m_Age <<
             ", height is " << i->m_Height << ", weight is " << i->m_Weight << endl;
    }
}

//自定义类型比较方式
bool comparePerson(Person &a, Person &b) {
    //年龄相同,按照身高降序
    if (a.m_Age == b.m_Age) {
        //身高相同,按照体重升序
        if (a.m_Height == b.m_Height) {
            return a.m_Weight < b.m_Weight;
        }
        return a.m_Height > b.m_Height;
    }
    //年龄升序  <
    return a.m_Age < b.m_Age;
}

void test01() {
    //1.创建容器
    list<Person> L;

    //2.创建人物
    Person p1("A", 35, 175, 50);
    Person p2("B", 40, 180, 51);
    Person p3("C", 40, 170, 23);
    Person p4("D", 25, 190, 60);
    Person p5("E", 35, 160, 65);
    Person p6("F", 35, 200, 55);
    Person p7("G", 15, 180, 60);
    Person p8("H", 15, 180, 50);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    L.push_back(p7);
    L.push_back(p8);

    printList(L);
    //Name is A, age is 35, height is 175, weight is 50
    //Name is B, age is 40, height is 180, weight is 51
    //...
    cout << "-----------------------------------" << endl;
    //排序后
    L.sort(comparePerson);
    printList(L);
    //年龄升序,身高降序,体重升序
    //Name is H, age is 15, height is 180, weight is 50
    //Name is G, age is 15, height is 180, weight is 60
    //Name is D, age is 25, height is 190, weight is 60
    //Name is F, age is 35, height is 200, weight is 55
    //Name is A, age is 35, height is 175, weight is 50
    //Name is E, age is 35, height is 160, weight is 65
    //Name is B, age is 40, height is 180, weight is 51
    //Name is C, age is 40, height is 170, weight is 23
}

int main() {
    test01();
    return 0;
}
