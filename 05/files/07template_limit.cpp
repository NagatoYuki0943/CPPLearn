#include <iostream>
#include <string>

using namespace std;

/**
 * 模板不是万能的,有些特定的数据类型,要使用具体化的方式做特殊实现
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

//对比两个数据是否相等
template<typename T>
bool myCompare(T &a, T &b) {
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

//利用具体化Person的版本实现代码,具体优先化代码 template<> 函数名
//Person比较时会优先调用它,而不是调用上面的
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
        cout << "a 等于 b" << endl;
    } else {
        cout << "a 不等于 b" << endl;
    }
}

void test02() {
    Person P1("小明", 10);
    Person P2("小红", 11);
    bool res = myCompare<Person>(P1, P2);
    if (res) {
        cout << "P1 等于 P2" << endl;
    } else {
        cout << "P1 不等于 P2" << endl;
    }
}


int main() {
    test01();
    test02();
    return 0;
}
