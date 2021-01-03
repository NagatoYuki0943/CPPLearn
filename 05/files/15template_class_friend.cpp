#include <iostream>
#include <string>
using namespace std;

/**
 * 全局函数类内实现: 直接在类内声明友元即可
 * 全局函数类外实现: 需要提前让编译器知道全局函数的存在
 */

//要提前写Person,不然下面的友元函数找不到类
template<class T1, class T2>
class Person;

//友元函数全局实现
template<class T1, class T2>
void printPerson2(Person<T1,T2> p){
    cout << "printPerson2 " << p.m_Name << " " << p.m_Age << endl;
}


template<class T1, class T2>
class Person {
    //在类里面写全局函数
    //全局函数类内实现: 直接在类内声明友元即可
    friend void printPerson1(Person<T1,T2> p){
        cout << "printPerson1 " << p.m_Name << " " << p.m_Age << endl;
    }

    //全局函数类外实现,需要让编译器提前知道这个函数的存在,写在上方  <>的含义是说明这个函数是模板函数
    friend void printPerson2<>(Person<T1,T2> p);
public:
    Person(T1 name, T2 age) {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};



// 全局函数类内实现测试
void test01(){
    Person<string, int> p1("Tom",10);
    //虽然是在class内部中写的,但是实际上是全局函数,因为是用了friend关键字修饰
    printPerson1(p1);
    //类外实现的全局函数直接调用会出错
    printPerson2(p1);
}
int main() {
    test01();
    return 0;
}
