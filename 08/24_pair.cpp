#include <iostream>

using namespace std;

/**
 * pair对组创建
 *  成对出现的数据，利用对组可以返回两个数据
 * 两种创建方式：
 *  pair<type, type> p ( value1, value2 );
 *  pair<type, type> p = make_pair( value1, value2 );
 *
 *  p.first p.second
 */

void test1(){
    pair<int, string> p1{1,"A"};
    cout << p1.first << " " << p1.second << endl;
    //1 A
}


int main(){
    test1();
    return 0;
}