#include <iostream>

using namespace std;

/**
 *  函数重(chong)载:函数名可以相同,提高复用性
 *  条件:1.在同一个作用域下
 *      2.函数名称相同
 *      3.函数的 参数类型不同 或 参数个数不同 或 顺序不同
 *  注意:函数的返回值不能作为函数重载的条件,只有返回值类型不同不能认定为两个不同的函数
 */

void func() {
    cout << "无参数func的调用" << endl;
}

void func(int a) {
    cout << "int a func的调用" << endl;
}

/*void func(const int a){   //普通变量加上const不会被认为是两个,只有引用传递才可以
    cout << "int a func的调用" << endl;
}*/
void func(int a, string str) {
    cout << "int a,string str func的调用" << endl;
}

void func(string str, int a) {
    cout << "int a,string str func的调用" << endl;
}
//注意:函数的返回值不能作为函数重载的条件,只有返回值类型不同不能认定为两个不同的函数
/*int func(string str,int a){
    cout << "int a,string str func的调用" << endl;
    return a;
}*/

int main() {
    int a = 0;
    string str;

    func();
    func(a);
    func(a, str);
    func(str, a);


    system("pause");
    return 0;
}
