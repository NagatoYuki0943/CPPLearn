#include <iostream>

using namespace std;

int main() {
    /**
     * 引用,给变量起别名,两者内存位置一样
     * int &别名=原名
     * 注意:引用必须初始化,初始化之后就不能变了
     */

    int a = 10, d = 20;
    int &b = a;
    //int &b=10; //错误,引用必须引用合法的内存空间
    //int &c;    //错误,必须初始化
    b = d;  //这个可以,这是让b=d的值20
    //int &b=d;  //错误,不能再更换引用对象

    cout << a << endl;  //20
    cout << b << endl;  //20
    b = 100;
    cout << a << endl;  //100
    cout << b << endl;  //100


    system("pause");
    return 0;
}
