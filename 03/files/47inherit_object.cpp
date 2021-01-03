#include <iostream>

using namespace std;

/**
 * 父类中的private子类无论什么继承都不能访问(只是被隐藏了,也会继承下去)
 */

class Base {
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son : public Base {
public:
    int m_D;
};

/**
 * 利用开发人员提示工具查看对象中的分布图
 *      Developer Command Prompt for VS 2019
 *      1.切换到cpp目录
 *      2. cl /d1 reportSingleClassLayout类名 文件名.cpp
 */
void test01() {
    cout << "size of Base :" << sizeof(Base) << endl;  //12,4*3=12
    cout << "size of Son :" << sizeof(Son) << endl;    //16,4*4=16 说明private也会被继承,只是被隐藏了
}

int main() {
    test01();
    system("pause");
    return 0;
}