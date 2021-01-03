#include <iostream>

using namespace std;

void swap1(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "值传递:a=" << a << " b=" << b << endl;
}

void swap2(int *a, int *b) {   //形式参数是指针
    int tmp;
    tmp = *a;     //转换都是用*p,使用解引用,不用会报错
    *a = *b;
    *b = tmp;
    cout << "地址传递:a=" << *a << " b=" << *b << endl;
}

int main() {
    //1.值传递,形参变化不改变实际参数的值
    int a = 1, b = 2;
    swap1(a, b);
    cout << "原函数:a=" << a << " b=" << b << endl;        //实际参数不会改变
    cout << endl;

    //地址传递
    //swap2(a,b);  //必须传入地址,否则报错
    swap2(&a, &b);
    cout << "原函数:a=" << a << " b=" << b << endl;        //实际参数也会改变

    return 0;
}