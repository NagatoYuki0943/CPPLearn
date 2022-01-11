#include <iostream>

using namespace std;


class Base{
public:
    //纯虚函数和抽象类
    virtual void func() = 0;

    virtual ~Base() = 0;
};


class Son: public Base{
public:
    //子类必须实例化,不然也是纯虚函数
    void func() override{
        cout << "Son.func" << endl;
    }

    ~Son() override= default;
};


int main(){
    //任何父类指针都能指向子类
    Base *pointer = new Son();
    pointer->func();
    delete pointer;
    return 0;
}