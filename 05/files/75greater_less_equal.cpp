#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/**
 * 关系仿函数
 *  实现关系对比
 * 仿函数原型：
 *  bool equal_to<T>                  //等于
 *  bool not_equal_to<T>              //不等于
 *  bool greater<T>                   //大于        greater<int>()
 *  bool greater_equal<T>             //大于等于
 *  bool less<T>                      //小于
 *  bool less_equal<T>                //小于等于
 */
void printVector(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

//仿函数
class MyCompare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

void test01() {
    vector<int> v{10, 30, 40, 20, 50};
    printVector(v);     //10 30 40 20 50

    //降序
    //使用自己的仿函数
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);     //50 40 30 20 10

    //使用编译器自带的 大于 greater<int>()
    sort(v.begin(), v.end(), greater<int>());
    printVector(v);     //50 40 30 20 10
}

int main() {
    test01();
    return 0;
}
