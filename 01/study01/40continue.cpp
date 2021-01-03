#include <iostream>

using namespace std;

int main() {
    //continue跳出本次循环继续执行接下来的循环
    for (int i = 0; i <= 100; i++) {
        if (i % 2 == 0) {      //是偶数对2取余是0,不输出
            continue;
        }
        cout << i << endl;
    }

    return 0;
}
