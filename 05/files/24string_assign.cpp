#include <iostream>
#include <string>

using namespace std;

/**
 * 给string字符串赋值操作
 * 赋值函数原型:
 *  string& operator=(const char* s);       //char*字符类型字符串 赋值给当前的字符串
 *  string& operator=(const string& s);     //把字符串s赋值给当前字符串
 *  string& operator=(char c);              //字符赋值给当前字符串
 *  string& assign(const char *s);          //把字符串s赋值给当前的字符串
 *  string& assign(const char *s,int n);    //把字符串s的前n个字符赋值给当前的字符串
 *  string& assign(const string &s);        //把字符串s赋值给当前字符串
 *  string& assign(int n, char c);          //用n个字符串c赋值给当前字符串
 */

void test01() {
    string str1;
    str1 = "hello world";
    cout << str1 << endl;       //hello world

    string str2;
    str2 = str1;
    cout << str2 << endl;       //hello world

    string str3;
    str3 = 'a';
    cout << str3 << endl;       //a

    string str4;
    str4.assign("hello C++");
    cout << str4 << endl;       //hello C++

    string str5;
    str5.assign("hello C++", 5); //前5个字符
    cout << str5 << endl;       //hello

    string str6;
    str6.assign(str5);
    //这样写是错误的,截取只能对 char * 有效
    //str6.assign(str5,3);
    cout << str6 << endl;       //hello

    string str7;
    str7.assign(8, 'w');
    cout << str7 << endl;       //wwwwwwww
}

int main() {
    test01();
    return 0;
}
