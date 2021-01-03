#include <iostream>

using namespace std;

int main() {
    //true  真 本质是1,非0
    //false 假 本质是0
    bool flag = true;
    cout << flag << " " << sizeof(flag) << endl;
    bool flag1 = false;
    cout << flag1 << " " << sizeof(flag1) << endl;
    return 0;
}
