#include <iostream>

using namespace std;

int main() {
    //运算符 +-*/
    int a = 10, b = 3;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << "\n" << endl;    //int只会输出3,会去除小数部分
    float c = 10, d = 3;
    cout << c / d << endl;
    //   % 取余数
    cout << a % b << endl;            //10%3=3......1
    int e = 10, f = 20;
    cout << e % f << endl;            //10%20=0......10
    //cout << c%d << endl;          //只有整形可以取余,浮点型不可以

    //递增
    int g1 = 2, h1 = ++g1;      //先加再赋值 3
    int g2 = 2, h2 = g2++;      //先赋值再加 2
    int g3 = 2, h3 = --g3;      //先减再赋值 1
    int g4 = 2, h4 = g4--;      //先赋值再减 2
    cout << h1 << endl;
    cout << h2 << endl;
    cout << h3 << endl;
    cout << h4 << endl;

    ///字符串运算
    string aa = "aaa";
    string bb = "bbb";
    string cc = aa + bb;
    //可以相加,相减,相乘,相除,取余不可以
    //string dd=aa-bb;
    //string ee=aa*bb;
    //string ff=aa/bb;
    //string gg=aa&bb;
    cout << cc << endl;  //输出aaabbb


    return 0;
}
