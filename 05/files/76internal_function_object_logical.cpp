#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/**
 * 逻辑仿函数
 *  实现逻辑运算
 * 函数原型：
 *  template<class T> bool logical_and<T>              //逻辑与
 *  template<class T> bool logical_or<T>               //逻辑或
 *  template<class T> bool logical_not<T>              //逻辑非    logical_not<bool>()
 *
 */
void printVector(const vector<bool> &v) {
    for (vector<bool>::const_iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    vector<bool> v1{true, false, true, false, false, true};
    printVector(v1);     //1 0 1 0 0 1

    //利用逻辑非,将容器v搬运到容器v2中
    vector<bool> v2;
    v2.resize(v1.size());

    //传输,源.begin(),源.end() ==> 目的.begin()    取反操作 logical_not<bool>()
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    printVector(v2);    //0 1 0 1 1 0    全部取反
}

int main() {
    test01();
    return 0;
}
