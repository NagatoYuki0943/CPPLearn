#include <iostream>

using namespace std;

/**
 * 从字符串中截取想要的字符串
 * 函数原型:
 *  string substr(int pos =0 ,int n = npos);    //返回由pos开始的n个字符组成的字符串
 *
 */

void substr() {
    string str = "abcdefghijklmn";
    string res = str.substr(0, 7);
    cout << res << endl;    //abcdefg

    //实用操作
    string email = "zhangsan@qq.com";
    int pos = email.find("@");
    string userName = email.substr(0, pos);  //从0开始,直接截取pos,因为pos从0开始算,@为8,从0开始,截取8个就能截取用户名
    cout << userName << endl;   //zhangsan
}

int main() {
    substr();
    return 0;
}
