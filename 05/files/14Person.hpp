#pragma once
#include <iostream>
#include <string>
using namespace std;
//将14Person.h和14Person.cpp文件写到一起,来包含这个文件,更好用

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age);

    void showPerson();

    T1 m_Name;
    T2 m_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson() {
    cout << "姓名:" << this->m_Name << " 年龄:" << this->m_Age << endl;
}