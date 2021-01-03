#include <iostream>

using namespace std;

/**
 * << 左移运算符,输出自定义的输出类型   operator<<
 * cout 属于 ostream    ostream  &cout 必须使用引用传递
 * 只能使用全局函数
 */
class Person {
    //使用友元让这个全局函数访问私有内容
    friend ostream &operator<<(ostream &cout, Person &p);

public:
    Person(int a, int b) : m_A(a), m_B(b) {}

private:
    int m_A;
    int m_B;
    //利用全局函数重载,左移运算符
    //不会利用成员函数来重载 << 运算符,因为无法实现 cout 在左侧(调用的话p会在左边)
    /*void operator<<(cout){  // operator<<(cout)相当于 p << cout
    }*/
};

///全局函数进行 << 重载
//注意返回值类型是ostream&,有引用
ostream &operator<<(ostream &cout, Person &p) {  //本质 operator<< (cout,p) 简化为 cout << p
    cout << "m_A=" << p.m_A << endl;            //传入的cout是别名,可以改名字
    cout << "m_B=" << p.m_B << endl;
    return cout;  //cout也是一个方法
}


void test01() {
    Person p(10, 10);
    cout << p << endl;   //直接输出对象,如果operator<< 函数没有返回值得话,后面不能加 << endl
}

int main() {
    test01();

    system("pause");
    return 0;
}
