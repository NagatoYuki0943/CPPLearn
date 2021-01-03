#include <iostream>

using namespace std;

int main() {
    // =  赋值
    // += 自己加上后面的
    // -= 自己减去后面的
    // *= 自己乘以后面的
    // /= 自己除以后面的
    // %= 自己用后面的取余
    int a = 10;
    a += 10;  //20
    cout << a << endl;

    a = 10;
    a -= 10;  //0
    cout << a << endl;

    a = 10;
    a *= 10;  //100
    cout << a << endl;

    a = 10;
    a /= 10;  //1
    cout << a << endl;

    a = 15;
    a %= 4;  //3
    cout << a << endl;
    return 0;
}
