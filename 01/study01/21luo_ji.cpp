#include <iostream>

using namespace std;

int main() {
    //逻辑
    // !    非 !a a为真 !a为假
    // &&   与 a && b 两个都为真才为真
    // ||   或 a || b 有一个为真就为真,两个全为假才是假
    int a = 10;
    cout << !a << endl;  //0 0为假
    int b = 5, c = 0;
    cout << (a && b) << " " << (a && c) << endl;
    //       10&&5=>1         10&&0=>0
    int d = 0;
    cout << (a || b) << " " << (a || c) << " " << (c || d) << endl;
    //       10||5=>1         10||0=>1         0||0=>0
    return 0;
}
