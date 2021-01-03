#include <iostream>

using namespace std;

int main() {
    //goto无条件跳转语句
    // goto 标记;       标记: (冒号)     如果标记的名称存在,执行到goto语句时,会跳转到标记的位置
    cout << "1" << endl;
    goto FLAG;

    cout << "2" << endl;
    cout << "3" << endl;
    FLAG:
    cout << "4" << endl;
    cout << "5" << endl;


    return 0;
}
