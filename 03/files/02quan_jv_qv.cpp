#include <iostream>

using namespace std;
#define A 10
//全局变量
int g_a = 10;
int g_b = 10;
//const修饰的全局变量,全局常量
const int c_g_a = 10;
const int c_g_b = 10;


int main() {
    //全局区

    //全局变量,静态变量,常量

    //创建普通局部变量,不在全局区
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址是:\t" << (long long) &a << endl;  //6487580    (int)&a强制转换成10进制,但是clion要使用long long
    cout << "局部变量b的地址是:\t" << (long long) &b << endl;  //6487576

    //内存地址开头位置不同,在全局区
    cout << "全局变量g_a的地址是:\t" << (long long) &g_a << endl;  //4206608
    cout << "全局变量g_b的地址是:\t" << (long long) &g_b << endl;  //4206612

    //静态变量,在全局区
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址是:\t" << (long long) &s_a << endl;  //4206616
    cout << "静态变量s_b的地址是:\t" << (long long) &s_b << endl;  //4206620

    //常量
    //字符串常量  "hello world" ,在全局区
    cout << "字符串常量的地址为:\t" << (long long) &"hello world" << endl;  //4210845

    //const修饰的变量
    //const修饰的全局变量,在全局区
    cout << "const修饰的全局变量c_g_a的地址为:\t" << (long long) &c_g_a << endl;  //4210688
    cout << "const修饰的全局变量c_g_b的地址为:\t" << (long long) &c_g_b << endl;  //4210692

    //const修饰的局部变量,不在全局区
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "const修饰的局部变量c_l_a的地址为:\t" << (long long) &c_l_a << endl;  //6487572
    cout << "const修饰的局部变量c_l_b的地址为:\t" << (long long) &c_l_b << endl;  //6487568


    //#define A 10
    //cout << "define常量量A的地址为:\t" << (long long)&A << endl;  //会报错

    system("pause");
    return 0;
}
