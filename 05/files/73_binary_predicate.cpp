#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 谓词概念
 * 概念：
 *  返回bool类型的仿函数称为谓词
 *  如果operator()接受一个参数，那么叫做一元谓词
 *  如果operator()接受两个参数，那么叫做二元谓词
 *
 */

//打印算法
void printVector(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

class MyCompare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

void test01() {
    vector<int> v{1, 4, 2, 3, 5};
    sort(v.begin(), v.end());
    printVector(v);     //1 2 3 4 5

    //使用函数对象,变为降序排列
    //谓词为对象
    MyCompare myCompare;
    sort(v.begin(), v.end(), myCompare);
    printVector(v);     //5 4 3 2 1

    //谓词使用匿名对象
    sort(v.begin(), v.end(), MyCompare());
    printVector(v);     //5 4 3 2 1
}

int main() {
    test01();
    return 0;
}
