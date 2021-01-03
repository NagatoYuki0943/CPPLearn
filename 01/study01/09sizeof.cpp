#include <iostream>

using namespace std;

int main() {
    //sizeof统计关键字的占内存大小
    //sizeof(类型/变量)
    long num3 = 10;
    cout << "short所占内存大小是:" << sizeof(short) << endl;
    cout << "int所占内存大小是:" << sizeof(int) << endl;
    cout << "long所占内存大小是:" << sizeof(num3) << endl;
    return 0;
}
