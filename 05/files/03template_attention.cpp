#include <iostream>
/**
 * 1.自动类型推导,必须推导出一致的数据类型才能使用
 * 2.模板必须要确定出T的数据类型才能使用
 */
using namespace std;

template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
//1.自动类型推导,必须推导出一致的数据类型才能使用

void test01() {
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a, b);
    cout << a << endl;
    cout << b << endl;

    //推导出的类型不一致,会报错
    //mySwap(a,c);
}

//2.模板必须要确定出T的数据类型才能使用
template<typename T>
void func() {
    cout << "func调用" << endl;
}

void test02() {
    //要指定数据类型,不写<int>会报错
    func<int>();
}


int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
