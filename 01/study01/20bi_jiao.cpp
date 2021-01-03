#include <iostream>

using namespace std;

int main() {
    //比较
    //  == 等于
    //  != 不等于
    //  <  小于
    //  >  大于
    //  <= 小于等于
    //  >= 大于等于
    int a = 4, b = 3;

    cout << (a == b) << endl; //0
    cout << (a != b) << endl; //1
    cout << (a > b) << endl;  //1
    cout << (a < b) << endl;  //0
    cout << (a >= b) << endl; //1
    cout << (a <= b) << endl; //0
    return 0;
}
