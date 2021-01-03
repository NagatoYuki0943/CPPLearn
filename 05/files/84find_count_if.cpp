#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * count_if
 * 按条件统计元素个数
 * 函数原型：
 *  count_if(iterator beg, iterator end, _Pred);
 *
 *  按条件统计元素出现次数
 *  beg 开始迭代器
 *  end 结束迭代器
 *  _Pred 谓词
 */

//函数
bool GreaterFive(int v) {
    return v > 5;
}

//谓词
class Greater5 {
public:
    bool operator()(int v) {
        return v > 5;
    }
};

//内置类型
void test01() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //函数
    //int sum = count_if(v.begin(), v.end(), GreaterFive);

    //谓词
    int sum = count_if(v.begin(), v.end(), Greater5());

    cout << "There are " << sum << " numbers are bigger 5." << endl;    //There are 6 numbers are bigger 5.
}

class Person {
public:
    Person(string name, int age) : m_Name(name), m_Age(age) {

    }

    string m_Name;
    int m_Age;
};

//函数
bool GreaterTwenty(const Person &p) {
    return p.m_Age > 20;
}

//谓词
class Greater20 {
public:
    bool operator()(const Person &p) {
        return p.m_Age > 20;
    }
};

//自定义类型计数
void test02() {
    vector<Person> v;
    Person p1("A", 30);
    Person p2("B", 30);
    Person p3("C", 35);
    Person p4("D", 20);
    Person p5("E", 15);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //函数
    int sum = count_if(v.begin(), v.end(), GreaterTwenty);
    //谓词
    //int sum = count_if(v.begin(),v.end(),Greater20());
    cout << "There are " << sum << " olds " << endl;        //There are 3 olds
}

int main() {
    test01();
    test02();
    return 0;
}
