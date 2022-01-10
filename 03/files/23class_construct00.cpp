#include <iostream>

using namespace std;
/**
 * 如果我们不提供构造和析构,编译器会提供,编译器提供的构造函数和析构函数是空的
 * 构造函数:主要作用在于创建时为对象的成员属性赋值,构造函数由编译器自动调用,无需手动调用
 * 析构函数:主要作用在于对象销毁前系统自动调用,执行一些清理工作
 * 两者在在public下外面才能访问
 */

/**
 * 构造函数语法: 类名(){}
 * 1.构造函数,没有返回值也不写void
 * 2.函数名称与类名相同
 * 3.构造函数可以有参数,因此可以发生重载
 * 4.程序在调用对象的时候会自动调用构造,无需手动调用,且只会调用一次
 */

/**
 * 析构函数语法: ~类名(){}
 * 1.析构函数,没有返回值也不写void
 * 2.函数名称与类名相同,在名称之前加上符号~
 * 3.析构函数不可以有参数,因此不能发生重载
 * 4.程序在对象销毁前会自动调用析构,无需手动调用,且只会调用一次
 */
class Person {
public: //在public下外面才能访问
    //构造函数:可以有参数
    Person() {   //没有返回值也不写void
        cout << "Person(){}构造函数调用" << endl;
    }

    //析构函数:不可以有参数
    ~Person() {  //没有返回值也不写void
        cout << "~Person(){}析构函数调用" << endl;
    }
};

///c++的类的构造函数可以再类内声明,类外实现
//建筑物
class Building {
public:
    Building();

    string m_SittingRoom; //客厅
private:
    string m_Bedroom;     //卧室
};

//类外写成员函数
Building::Building() {
    m_SittingRoom = "客厅";
    m_Bedroom = "卧室";
}

void test01() {
    Person p1; //会自动调用Person构造函数,析构函数
}

int main() {
    test01();


    system("pause");
    return 0;
}
