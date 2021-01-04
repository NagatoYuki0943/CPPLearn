#include <iostream>

using namespace std;
/**
 * 普通函数与函数模板的区别:
 *  1.普通函数调用时可以发生自动类型转换(隐式类型转换)
 *  2.函数模板调用时,如果利用自动类型推导,不会发生隐式转换;
 *  3.如果利用显示指定类型的方式,可以发生隐式类型转换
 */

int myAdd01(int a, int b) {
    return a + b;
}

template<typename T>
T myAdd02(T a, T b) {
    return a + b;
}

void test01() {
    int a = 1, b = 2;
    char c = 'c';
    double d = 100.1;

    //1.普通函数调用时可以发生自动类型转换(隐式类型转换)
    int res = myAdd01(a, b);
    cout << res << endl;    //3
    //c被隐式转换成了int类型
    res = myAdd01(a, c);
    cout << res << endl;    //100

    //2.函数模板调用时,如果利用自动类型推导,不会发生隐式转换;
    res = myAdd02(a , b);
    cout << res << endl;    //3
    //自动判断不能隐式转换,会报错
    //res = myAdd02(a , c); 字符和浮点都不能自动转换
    //res = myAdd02(a , d);

    //3.如果利用显示指定类型的方式,可以发生隐式类型转换
    res = myAdd02<int>(a,c);
    cout << res << endl;    //100
}

int main() {
    test01();
    return 0;
}
