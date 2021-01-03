#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * swap
 * 功能描述：
 *  互换两个容器的元素
 * 函数原型：
 * swap(container c1, container c2);
 * 互换两个容器的元素
 * c1 容器1
 * c2 容器2
 */

//打印仿函数
class PrintVector {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

void test01() {
    vector<int> vector1{0, 1, 2, 3};
    vector<int> vector2{4, 5, 6};
    cout << "before swap:" << endl;
    for_each(vector1.begin(), vector1.end(), PrintVector());      //0 1 2 3
    cout << endl;
    for_each(vector2.begin(), vector2.end(), PrintVector());      //4 5 6
    cout << endl;

    //交换
    swap(vector1, vector2);
    cout << "after swap:" << endl;
    for_each(vector1.begin(), vector1.end(), PrintVector());      //4 5 6
    cout << endl;
    for_each(vector2.begin(), vector2.end(), PrintVector());      //0 1 2 3
    cout << endl;

}

int main() {
    test01();
    return 0;
}
