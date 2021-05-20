#include <iostream>

using namespace std;

int main() {
    int a = 10;
    //取地址
    cout << &a << endl; //0x62fe1c
    //指针, &a取地址
    int *b = &a;
    cout << b << endl;  //0x62fe1c
    cout << *b << endl; //10
    //引用
    int &c = a;
    cout << c << endl;  //10
    return 0;
}
