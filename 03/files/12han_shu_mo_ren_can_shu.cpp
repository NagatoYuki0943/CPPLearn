#include <iostream>

using namespace std;

/**
 * 函数默认参数
 * 如果我们传入参数,就用传入的,不传入就是用默认值
 */

/** 注意事项:
 * 1.如果某个位置已经有了默认参数,name从这个位置往后,从左到右必须有默认值
 */
/*int func1(int a,int b=10,int c){   //c没有默认值就会报错

} */

/**
 * 2.如果函数声明有默认参数,函数实现就不能有默认参数
 * 声明和实现对于同一个参数只能有一个默认参数
 */
//声明
int func2(int a, int b = 2);

//实现
int func2(int a = 2, int b) {   //实现给了默认参数会报错,不过如果a在声明时不给,实现的时候给了是可以的
    return a + b;
}


int func(int a, int b = 10, int c = 20) {
    return a + b + c;
}

int main() {
    int a = 10;
    cout << func(a) << endl;  //40

    func2();
    system("pause");
    return 0;
}
