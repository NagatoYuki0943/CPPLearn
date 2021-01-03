#include <iostream>

using namespace std;

/**
 * 占位参数,只填数据类型
 *  int func(int a,int)
 *  占位参数可以有默认参数
 */
void func(int a, int) {
    cout << "This is " << a << " function" << endl;
}

/**
 * 占位参数可以有默认参数,调用时不用填了
 */
void func1(int a, int = 10) {

}

int main() {
    func(10, 12); //调用的时候必须传入相应类型的数据

    system("pause");
    return 0;
}
