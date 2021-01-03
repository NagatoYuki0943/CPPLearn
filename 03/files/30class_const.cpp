#include <iostream>

using namespace std;

/**
 * C++中类的常量可以由对象来访问,但是不能由类名来访问,因为不是静态的,要想使用类名来访问,要加上 constexpr 修饰
 * php中对象没法访问常量 因为 $m->PI 相当于 访问 $PI 但是里面没有这个变量
 */
class Math {
public:
    //常量
    const double PI = 3.14;
    //静态常量,要加上 constexpr,const 可以去掉
    constexpr static const double E = 2.7;
};

int main() {
    Math m;
    cout << m.PI << endl;       //3.14
    //Math::PI; //会报错,因为不是静态属性
    cout << m.E << endl;        //2.7
    cout << Math::E << endl;    //2.7
    return 0;
}
