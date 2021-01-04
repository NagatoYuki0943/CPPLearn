#include <iostream>
#include <string>

using namespace std;

/**
 * string字符串存取
 *  string中单个字符存取的方式有两种
 *      char& operator[](int n) //通过[]数组方式存取
 *      char& at(int n)         通过at()方式存取
 *
 * 获取之后可以对原值进行重新赋值
 */

void read() {
    string str = "hello";

    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] << " ";  //h e l l o
    }
    cout << endl;
    for (int i = 0; i < str.size(); ++i) {
        cout << str.at(i) << " ";   //h e l l o
    }
    cout << endl;
}

void save() {
    string str = "BASIC";
    str[0] = 'X';
    cout << str << endl;    //XASIC
    str.at(1) = 'M';
    cout << str << endl;    //XMSIC
}

int main() {
    read();
    save();
    return 0;
}
