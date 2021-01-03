#include <iostream>
#include <string>
using namespace std;
//解决方式1:直接包含 .cpp   将 #include "14Person.h" 改为 #include "14Person.cpp"  不常用
//#include "14Person.cpp"

//解决方式2: 将声明和实现写到一个文件中,并更改后缀名问 .hpp hpp是约定的名称,并不是强制       常用
#include "14Person.hpp"
/**
 * 问题:
 *      类模板中成员函数创建时机是在调用阶段,导致分文件编写时链接不到
 * 解决:
 *      解决方式1:直接包含 .cpp
 *          将 #include "14Person.h" 改为 #include "14Person.cpp"
 *          注意,源文件还是 .cpp,不过包含时改名字
 *          不常用
 *      解决方式2: 将声明和实现写到一个文件中,并更改后缀名问 .hpp hpp是约定的名称,并不是强制
 *      放到一起
 *          常用
 */

//template<class T1, class T2>
//class Person {
//public:
//    Person(T1 name, T2 age);
//
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};

//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//    cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << endl;
//}


void test01(){
    Person<string, int> p("小兰",17);
    p.showPerson();
}

int main() {
    test01();
    return 0;
}
