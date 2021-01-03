#include <iostream>

using namespace std;

//1.无参无返
void test01() {
    cout << "test01" << endl;
}

//2.有参无返
void test02(int a) {
    cout << "test02->a=" << a << endl;
}

//3.无参有返
int test03() {
    return 100;
}

//4.有参有返
int add(int a, int b) {        //自己定义的函数要放在main函数外面
    int sum = a + b;
    return sum;
}

int main() {
    //调用方法
    test01();
    int a = 5;
    test02(a);
    int b = test03();
    cout << "test03->b=" << b << endl;
    int c = 5, d = 10, e;
    e = add(c, d);
    cout << "test04->sum=" << e << endl;
    return 0;
}