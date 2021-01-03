#include <iostream>
//#define宏常量
//cout << "性别:" << (abs->personArray[ret].m_Sex==1 ? "男":"女") << "\t"; 注意用小括号括起来输出的命令
#define DAY 7
using namespace std;

int main() {
    //const修饰变量也是常量
    const int a = 9;
    cout << "一星期有" << DAY << "天" << endl;
    cout << "a=" << a << endl;
    return 0;
}
