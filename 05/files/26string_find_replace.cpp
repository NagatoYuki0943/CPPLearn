#include <iostream>

using namespace std;

/**
 * string查找和替换
 * 查找：查找指定字符串是否存在
 * 替换：在指定的位置替换字符串
 * 函数原型：
 *  查找函数没有返回-1,找到返回位置
 *
 * find从左往右数查找第一个
 *  int find(const string &str, int pos = 0) const;         //查找str第一次出现位置,从pos开始查找
 *  int find(const char* s,     int pos = 0) const;         //查找s第一次出现位置,从pos开始查找
 *  int find(const char* s,     int pos, int n) const;      //从pos位置查找s的前n个字符第一次位置
 *  int find(const char c,      int pos = 0) const;         //查找字符c第一次出现位置
 *
 * rfind从右往左数查找第一个,结果还是从左往右数
 *  int rfind(const string& str, int pos = npos) const;     //查找str最后一次位置,从pos开始查找
 *  int rfind(const char* s,     int pos = npos) const;     //查找s最后一次出现位置,从pos开始查找
 *  int rfind(const char* s,     int pos, int n) const;     //从pos查找s的前n个字符最后一次位置
 *  int rfind(const char c,      int pos = 0) const;        //查找字符c最后一次出现位置
 *
 *  string& replace(int pos, int n, const string &str);     //替换从pos开始的n个字符为字符串str
 *  string& replace(int pos, int n,const char* s); `        //替换从pos开始的n个字符为字符串s
 *
 */

void find() {
    string str1 = "abcdefg";

    //find从左往右数查找第一个
    int position = str1.find('a');
    cout << "position = " << position << endl;  //position = 0
    position = str1.find("de");
    cout << "position = " << position << endl;  //position = 3
    position = str1.find("asa");
    cout << "position = " << position << endl;  //position = -1 没有返回 -1

    //rfind从右往左数查找第一个
    position = str1.rfind("f");
    cout << "position = " << position << endl;  //position = 5


}

void replace() {
    string str1 = "abcdefg";
    str1.replace(1, 3, "11111");
    cout << str1 << endl;   //a11111efg

    string str2 = "abcdefg";
    string str3 = "***";
    str2.replace(1, 2, str3);
    cout << str2 << endl;   //a***defg
}


int main() {
    find();
    replace();
    return 0;
}
