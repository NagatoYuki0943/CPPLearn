#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/**
 * find_if
 * 按条件查找元素
 * 函数原型：
 *  find_if(iterator beg, iterator end, _Pred);
 *
 *  按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 *  beg 开始迭代器
 *  end 结束迭代器
 *  _Pred 函数或者谓词（返回bool类型的仿函数）
 */

//函数
bool GreaterFive(int v) {
    return v > 5;
}

//谓词
class Greater5 {
public:
    //大于5的数
    bool operator()(int v) {
        return v > 5;
    }
};

//查找内置数据类型
void test01() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //函数或者谓词都可以
    vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive);
    //vector<int>::iterator pos = find_if(v.begin(), v.end(), Greater5());
    if (pos != v.end()) {
        cout << *pos << endl;       //6

    } else {
        cout << "not found" << endl;
    }
}

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {
    }
    string m_Name;
    int m_Age;
};

//函数
bool GreaterTwenty(Person &p) {
    return p.m_Age > 20;
}

//谓词
class Greater20 {
public:
    bool operator()(Person &p) {
        return p.m_Age > 20;
    }
};

//自定义数据类型条件查找
void test02() {
    vector<Person> v;
    Person p1("A", 4);
    Person p2("B", 9);
    Person p3("C", 88);
    Person p4("D", 48);
    Person p5("E", 15);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //找年龄大于20的人
    //函数
    vector<Person>::iterator pos = find_if(v.begin(), v.end(), GreaterTwenty);
    //仿函数
    //vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
    if (pos != v.end()) {
        cout << pos->m_Name << " " << pos->m_Age << endl;       //C 88
    } else {
        cout << "not found" << endl;
    }
}

int main() {
    test01();
    test02();
    return 0;
}
