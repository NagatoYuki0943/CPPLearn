#include <iostream>

using namespace std;

/**
 * 子类构建也会构建父类
 * 继承中构造和析构顺序
 * 先父类构造,后子类构造  现有父类,再有子类
 * 先子类析构,后父类析构  先毁子类,再毁父类
 *
 */
class Base {
public:
    Base() {
        cout << "Base构造函数" << endl;
    }

    ~Base() {
        cout << "Base析构函数" << endl;
    }
};

class Son : public Base {
public:
    Son() {
        cout << "Son构造函数" << endl;
    }

    ~Son() {
        cout << "Son析构函数" << endl;
    }
};

void test01() {
    Son son01;
}

int main() {
    test01();
    system("pause");
    return 0;
}