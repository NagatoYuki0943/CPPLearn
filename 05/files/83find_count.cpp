#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
/**
 * count
 * 统计元素个数
 * 函数原型：
 *  count(iterator beg, iterator end, value);
 *
 *  统计元素出现次数
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 统计的元素
 *
 */
//内置数据类型
void test01() {
    deque<int> d{1, 2, 3, 4, 1, 5, 4, 6, 2, 1, 3, 5, 63, 1};
    int sum = count(d.begin(), d.end(), 1);
    cout << "sum 1 is " << sum << endl;     //sum 1 is 4

}

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {
    }

    //重载 ==
    bool operator==(const Person &p) {
        //只统计年龄相同的
        if (this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }

    string m_Name;
    int m_Age;
};

//自定义数据类型
void test02() {
    deque<Person> d;
    Person p1("A", 35);
    Person p2("B", 35);
    Person p3("C", 35);
    Person p4("D", 40);
    Person p5("E", 40);
    d.push_back(p1);
    d.push_back(p2);
    d.push_back(p3);
    d.push_back(p4);
    d.push_back(p5);

    Person p6("F", 35);
    int sum = count(d.begin(), d.end(), p6);
    cout << "The 35 years old people's number is " << sum << endl;  //The 35 years old people's number is 3
}

int main() {
    test01();
    test02();
    return 0;
}
