#include <iostream>

using namespace std;
/**
 *  函数模板和函数重名
 * 调用规则如下:
 *  1.如果函数模板和普通函数都可以实现,优先调用普通函数
 *  2.可以通过空模板参数列表  <> 来前置调用函数模板
 *  3.函数模板也可以发生重载
 *  4.如果函数模板可以产生更好的匹配,优先调用函数模板
 *
 *  最好不要出现同名函数和模板
 */

//普通函数
void myPrint(int a, int b) {
    cout << "int a, int b 普通函数调用" << endl;
}

//函数模板
template<typename T>
void myPrint(T a,T b){
    cout << "T a,T b 模板函数调用" << endl;
}

//模板重载
template<typename T>
void myPrint(T a){
    cout << "T a 模板函数调用" << endl;
}


void test01(){
    //1.如果函数模板和普通函数都可以实现,优先调用普通函数
    myPrint(1,2);         //int a, int b 普通函数调用

    //2.可以通过空模板参数列表  <> 来前置调用函数模板
    myPrint<>(1,2);      //T a,T b 模板函数调用
    myPrint<int>(1,2);   //T a,T b 模板函数调用

    //3.函数模板也可以发生重载
    myPrint(3);             //T a 模板函数调用


    //4.如果函数模板可以产生更好的匹配,优先调用函数模板
    //char类型在模板直接判断,而函数要转换成数字,编译器任务前者更加简单
    char c1='a';
    char c2='b';
    myPrint(c1,c2);            //T a,T b 模板函数调用
}


int main() {
    test01();
    return 0;
}
