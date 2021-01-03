#include <iostream>

using namespace std;

int main() {
    //短整型,2字节 -32768 32767
    short num1 = 32768; //超出上限变为最小值
    //整形,4字节
    int num2 = 32768;
    //长整形,win4字节,linux32位4字节,64位8字节
    long num3 = 10;
    //长长整形,8字节
    long long num4 = 10;

    //浮点型
    //float 4字节  7位有效数字   默认小数显示6位有效数字
    //double 8字节 15-16位有效数字    默认小数显示6位有效数字
    //科学计数法  3e2=3*10^2 3e-2=3*10^(-2)
    float num5 = 152.54316f;  //后面写上f,不写的话会变成双精度
    double num6 = 154650.45687;
    float num7 = 3e2;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    cout << "num3=" << num3 << endl;
    cout << "num4=" << num4 << endl;
    cout << "num5=" << num5 << endl;   //默认小数显示6位有效数字
    cout << "num6=" << num6 << endl;   //默认小数显示6位有效数字
    cout << "num7=" << num7 << endl;
    return 0;
}