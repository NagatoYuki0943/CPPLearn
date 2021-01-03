#include <iostream>

using namespace std;

int main() {
    /*
     * 表达式1 ? 表达式2 : 表达式3
     * 1为真,执行2,否则执行3
     */
    int a, b, c;
    /*cin >> a >> b;
    //a>=b ? c=a : c=b;
    c=(a>=b ? a : b);   //和上面一样
    cout << "c=" << c <<endl;*/

    //在c++中,三目运算返回的是变量,可以继续赋值
    cin >> a >> b;
    //c=(a>=b ? a : b)=100;     //这样c一直等于100
    (a > b ? a : b) = 100;     //如果a>b,则选择a,并让a=100 否则让b=100
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
