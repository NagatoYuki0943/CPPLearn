#include <iostream>

using namespace std;

/**
 * 字符串之间的比较
 * 比较方式:
 *  字符串比较是按照字符的ASCII码进行比较
 *      = 返回 0
 *      > 返回 1
 *      < 返回 -1
 *
 * 函数原型:
 *  int compare(const string &s) const; //与字符串s比较
 *  int compare(const char *s) const;   //与字符串s比较
 *
 */

void compare() {
    string str1 = "hello";
    string str2 = "xello";
    if (str1.compare(str2) == 0) {
        cout << "str1 == str2" << endl;
    } else if (str1.compare(str2) == 1) {
        cout << "str1 > str2" << endl;
    } else {
        cout << "str1 < str2" << endl;
    }
}

int main() {
    compare();
    return 0;
}
