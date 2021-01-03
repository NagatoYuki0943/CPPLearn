#include <iostream>

using namespace std;

/**
 * 引用的本质是在c++内部中实现是一个指针常量 int * const p
 * 指针的指向不能改变,指向的内容可以改变
 */
void func(int &ref) {
    ref = 100;//ref是引用,转换为*ref是100
}

int main() {
    int a = 0;

    //自动转换为 int * const ref=&a ;指针常量:指向不能改变,
    int &ref = a;
    ref = 20;//内部发现是ref引用,自动转换为*ref=20

    cout << "a=" << a << endl;    //20
    cout << "ref=" << ref << endl;//20

    func(a);
    cout << "a=" << a << endl;    //100



    system("pause");
    return 0;
}
