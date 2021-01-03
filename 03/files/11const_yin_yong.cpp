#include <iostream>

using namespace std;

/**
 * 常量引用:用来修饰形参防止误操作
 * (const int &val)  showValue(10); 后面可以直接传递常量
 */
void showValue(const int &val) { //const 防止更改
    //val=1000; //a也会变成1000
    cout << "val=" << val << endl;
}

int main() {
    //int a = 10;
    //int &ref = a;
    //int &ref = 10; //错误,引用必须引用合法的内存空间
    //加上const之后,编译器将代码修改为int temp=10;const int& ref=temp;
    //const int &ref1 = 10;
    //ref1=10;  //不能修改,加入const之后变为常量,不能修改

    int a = 100;
    showValue(a);
    cout << "a=" << a << endl;

    system("pause");
    return 0;
}
