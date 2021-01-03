#include <iostream>
#include <string>

using namespace std;

/**
 * string字符串拼接
 * 函数原型
 *  string& operator+=(const char* str);                //重载+=操作符
 *  string& operator+=(const char c);                   //重载+=操作符
 *  string& operator+=(const string & str);             //重载+=操作符
 *  string& append(const char *s);                      //把字符串s连接到当前字符串结尾
 *  string& append(const char *s,int n);                //把字符串s的前n个字符连接到当前字符串结尾
 *  string& append(const string &s);                    //同 string& operator+=(const string & str);
 *  string& append(const string & s, int pos, int n);   //字符串s中从pos开始的n个字符连接到字符串结尾, pos从0开始计数
 *
 */

void test01() {
    string str1 = "hello ";
    char *str = "world ";

    str1 += str;
    cout << str1 << endl;   //hello world

    str1 += 'a';
    cout << str1 << endl;   //hello world a

    string str2 = " bcd";
    str1 += str2;
    cout << str1 << endl;   //hello world a bcd

    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;   //I love

    str3.append("game abcde", 4);
    cout << str3 << endl;   //I love game

    str3.append(str2);
    //这样写是错误的,截取只能对 char * 有效
    //str3.append(str3,3);
    cout << str3 << endl;   //I love game bcd

    string str4 = "hijklmn";
    str3.append(str4, 2, 4);
    cout << str3 << endl;   //I love game bcdjklm
}

int main() {
    test01();
    return 0;
}
