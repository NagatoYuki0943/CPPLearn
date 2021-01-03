#include <iostream>

using namespace std;
/**
 * 类模板中成员函数创建时机
 *
 * 类模板中成员函数和普通类中成员函数的创建时机是有区别的
 *      普通类的成员函数在以开始就创建
 *      类模板的成员函数在调用时才创建
 */

class Person1{
public:
    void showPerson1(){
        cout << "Person1 show" << endl;
    }
};


class Person2{
public:
    void showPerson2(){
        cout << "Person2 show" << endl;
    }
};

template<class T>
class myClass{
public:
    T obj;
    //类模板中的成员函数
    void func1(){
        obj.showPerson1();
    }

    void func2(){
        obj.showPerson2();
    }
};

void test01(){
    myClass<Person1> m1;
    m1.func1();
    //m1.func2();   会报错,因为 m1 中的 T 是 Person1
}

int main() {
    test01();
    return 0;
}
