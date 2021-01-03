#include <iostream>
#include <string>

using namespace std;

/**
 * string字符串进行插入和删除操作
 * 函数原型:
 *  string& insert(int pos, const char* s);         //插入字符串
 *  string& insert(int pos, const string& str);     //插入字符串
 *  string& insert(int pos, int n, char c);         //在指定位置插入n个字符c
 *
 *  string& erase(int pos,  int n = npos);`         //删除从Pos开始的n个字符
 */

void insert() {
    string str = "abcedfg";
    //str.insert(1,'a');    //报错,不支持 char
    str.insert(1, "***");
    cout << str << endl;    //a***bcedfg

    string str1 = "|||";
    str.insert(2, str1);
    cout << str << endl;    //a*|||**bcedfg
}

void erase() {
    string str = "a*|||**bcedfg";
    str.erase(1, 6);
    cout << str << endl;    //abcedfg
}

int main() {
    insert();
    cout << "-----------" << endl;
    erase();
    return 0;
}
