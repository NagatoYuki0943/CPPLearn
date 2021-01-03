#include <iostream>
#include <string>

using namespace std;

/**
 * pair对组创建
 *  成对出现的数据，利用对组可以返回两个数据
 * 两种创建方式：
 *  pair<type, type> p ( value1, value2 );
 *  pair<type, type> p = make_pair( value1, value2 );
 */
void test01() {
    //第一种方式
    pair<int, string> p1(1, "hello");
    //获取两个数据
    cout << p1.first << " " << p1.second << endl;   //1 hello

    //第二种方式
    pair<string, int> p2 = make_pair("Tom", 15);
    cout << p2.first << " " << p2.second << endl;   //Tom 15
}

int main() {
    test01();
    return 0;
}
