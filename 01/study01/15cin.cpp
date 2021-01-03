#include <iostream>

using namespace std;

int main() {
    //输入语法
    //cin >> a  a要提前定义
    //cin >> a >> b;  输入多个
    int a = 0;
    cout << "请输入整形变量" << endl;
    cin >> a;
    cout << a << endl;

    float b = 0;
    cout << "请输入浮点型变量" << endl;
    cin >> b;
    cout << b << endl;

    char c;
    cout << "请输入字符变量" << endl;
    cin >> c;
    cout << c << endl;

    string d;
    cout << "请输入字符串变量" << endl;
    cin >> d;
    cout << d << endl;

    bool e;
    cout << "请输入bool变量" << endl;
    cin >> e;
    cout << e << endl;
    return 0;
}
