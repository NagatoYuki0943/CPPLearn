#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
/**
 * 常用查找算法
 *  掌握常用的查找算法
 * 算法简介：
 *  find                //查找元素
 *  find_if             //按条件查找元素
 *  adjacent_find       //查找相邻重复元素
 *  binary_search       //二分查找法
 *  count               //统计元素个数
 *  count_if            //按条件统计元素个数
 *
 * find
 *  查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
 * 函数原型：
 *  find(iterator beg, iterator end, value);
 *  按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置 end()代表最后一个数据的下一个位置
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 查找的元素
 */

//查找内置数据类型
void test01() {
    vector<int> v{1, 2, 5, 3, 5, 0, 6, 7, 89};

    vector<int>::iterator pos = find(v.begin(), v.end(), 0);
    if (pos != v.end()) {
        cout << *pos << endl;   //0
    } else {
        cout << "not found" << endl;
    }
    pos = find(v.begin(), v.end(), 50);
    if (pos != v.end()) {
        cout << *pos << endl;
    } else {
        cout << "not found" << endl;    //not found
    }
}

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {
    }

    //重载 == 号,让底层知道如何对比Person数据类型
    bool operator==(const Person &p) const {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};
//查找自定义数据类型
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

    //第三个参数填自定义类型对象的名字
    vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
    if (pos != v.end()) {
        cout << pos->m_Name << " " << pos->m_Age << endl;   //B 9
    } else {
        cout << "not found" << endl;
    }

    //使用另一个Person和vector作对比,这样更合理
    Person p6("E", 15);

    pos = find(v.begin(), v.end(), p6);
    if (pos != v.end()) {
        cout << pos->m_Name << " " << pos->m_Age << endl;   //E 15
    } else {
        cout << "not found" << endl;
    }
}

int main() {
    test01();
    test02();
    return 0;
}
