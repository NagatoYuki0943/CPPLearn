#include <iostream>

using namespace std;

/**
 * c++中空指针也是可以调用成员函数的,但是也要注意有没有用到this指针
 * 写法:  Person *p=NUll;
 * 如果用到this指针,需要加以判断保证代码健壮性
 */

class Person {
public:
    void showClassName() {
        cout << "this is Person class" << endl;  //只输出字符串常量
    }

    void showPersonAge() {
        //报错原因是传入的指针是NULL
        //有了这个判断就可以排除错误了,为空就不访问
        if (this == NULL) {
            return;
        }
        cout << "age=" << m_Age << endl;        //输出了当前对象中的变量
    }

    int m_Age;
};

void test01() {
    Person *p = NULL;       //没有确切的对象
    p->showClassName();   //这个可以访问
    p->showPersonAge();   //这个默认不能访问
}


int main() {
    test01();

    system("pause");
    return 0;
}
