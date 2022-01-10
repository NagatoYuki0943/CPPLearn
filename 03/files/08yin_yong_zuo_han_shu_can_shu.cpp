#include <iostream>

using namespace std;
/**
 * 引用可以作为函数参数修改实参,和指针相同
 */
//1.值传递
void mySwap01(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

//2.地址传递
void mySwap02(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//3.引用传递
void mySwap03(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 10, b = 20;
    mySwap01(a, b);   //值传递
    cout << "a=" << a << " b=" << b << endl;  //10 20 没有发生改变
    mySwap02(&a, &b); //地址传递
    cout << "a=" << a << " b=" << b << endl;  //20 10 发生改变
    mySwap03(a, b); //引用传递
    cout << "a=" << a << " b=" << b << endl;  //10 20 发生改变,把上面改回来了


    system("pause");
    return 0;
}
