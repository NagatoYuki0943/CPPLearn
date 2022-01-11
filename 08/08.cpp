#include <iostream>
using namespace std;

class Drinking{
public:
    //煮水
    virtual void boil() = 0;
    //冲泡
    virtual void brew() = 0;
    //倒入杯中
    virtual void pourInCpu() = 0;
    //加入调料
    virtual void addSomeThing() = 0;

    //父类的函数也能指向子类的实际方法
    void make(){
        this->boil();
        this->brew();
        this->pourInCpu();
        this->addSomeThing();
    }
};


class Coffee: public Drinking{
public:
    void boil() override{
        cout << "煮水" << endl;
    }
    void brew() override{
        cout << "冲咖啡" << endl;
    }
    void pourInCpu() override{
        cout << "导入咖啡杯" << endl;
    }
    void addSomeThing() override{
        cout << "加入糖" << endl;
    }
};


class Tea: public Drinking{
public:
    void boil() override{
        cout << "煮水" << endl;
    }
    void brew() override{
        cout << "泡茶" << endl;
    }
    void pourInCpu() override{
        cout << "导入茶杯" << endl;
    }
    void addSomeThing() override{
        cout << "加入蜂蜜" << endl;
    }
};


int main(){
    Drinking *p;
    p = new Coffee();
    p->make();
    p = new Tea();
    p->make();
}