#include <iostream>

using namespace std;

/**
 * 纯虚函数和抽象类
 * 在多态中,通常父类中虚函数的实现是毫无意义的,主要都是调用子类重写的内容,因此可以将虚函数改为纯虚函数
 * 纯虚函数语法 : virtual 返回值类型 函数名 (参数列表) = 0;
 * 当类中有了纯虚函数,这个类也成抽象类
 *      抽象类特点:
 *          1.无法实例化对象
 *          2.子类必须重写抽象类中的纯虚函数,否则也属于抽象类
 */

class Base {
public:
    ///纯虚函数,前面必须有virtual后面才能等于0
    ///当类中有了纯虚函数,这个类也成抽象类
    virtual void func() = 0;


    virtual ~Base() = 0;
};

class Son : public Base {
public:
    void func() override {
        cout << "func函数调用" << endl;
    }

    ~Son() override = default;
};

void test01() {
    //Base b1;  //报错,抽象类不能实例化
    //new Base; //报错,抽象类不能实例化
    Son s1;  //子类如果不重写父类的纯虚函数,子类也是抽象类,也不能实例化
    Base *pointer;    //任何父类指针都能指向子类
    pointer = new Son;
    pointer->func();
    delete pointer;
}

int main() {
    test01();
    system("pause");
    return 0;
}

