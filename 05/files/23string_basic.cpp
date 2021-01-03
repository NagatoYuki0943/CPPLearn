#include <iostream>
#include <string>

using namespace std;

/**
 * 1.string本质
 *  string是C++风格的字符串,本质上是一个类
 *
 * 2.string和char*区别
 *  char* 是一个指针
 *  string是一个类,类内部封装了char*,管理这个字符串,是一个char*型的容器
 *
 * 3.特点
 *  string类内部封装了很多成员方法
 *  例如: 查找find,复制copy,删除erase,替换replace,插入insert
 *  string管理char*所分配的内容,不用担心复制越界和取值越界等,由类内部进行负责
 *
 * 4.string构造函数
 *  string()                    默认构造,创建一个空的字符串 如 string str
 *  string(const char* s)       使用字符指针初始化,使用字符s初始化
 *  string(const string& str)   使用字拷贝构造初始化,使用字符串str初始化另一个string对象
 *  string(int n,char c)        使用n个字符c初始化
 *
 * 5.size()返回长度
 */

void test01() {
    //默认构造
    string s1;

    //使用字符指针初始化
    const char *str = "hello world";
    string s2(str);
    cout << s2 << endl; //hello world

    //使用字拷贝构造初始化
    const string s3(s2);
    cout << s3 << endl; //hello world

    string s4(10, 'a');
    cout << s4 << endl; //aaaaaaaaaa

}

int main() {
    test01();
    return 0;
}
