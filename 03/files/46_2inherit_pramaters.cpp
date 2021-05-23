#include <iostream>

using namespace std;

/**
 * C++子类继承不能继承父类的构造函数,
 * C#子类继承不能继承父类的构造函数
 * 但是实例化子类会连带(提前)实例化父类,所以如果父类有有参构造函数,就要显示调用父类构造参数
 * 父类构造函数有参数要用如下写法
 */

/**
 * C++子类继承不能继承父类的构造函数,
 * C#子类继承不能继承父类的构造函数
 * PHP子类可以继承父类的构造和析构方法(php中构造方法是普通方法,遵循普通方法规律)
 *      要注意继承时父类的构造方法的初始化也对子类有效
 */
class Vehicle {
public:
    //父类构造方法有参数
    Vehicle(string name) {
        m_Name = name;
    }

    string m_Name;
};


class Car : public Vehicle {
public:

    /**
     * 子类要这样写才不会出错,要把子类的参数传给父类
     */
    Car(string name) : Vehicle(name) {
        m_Name = name;
    }
};

void test() {
    Car car("Ford");
    cout << car.m_Name << endl;
}

int main() {
    test();

    return 0;
}
