#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * reverse
 * 将容器内元素进行反转
 * 函数原型：
 *  reverse(iterator beg, iterator end);
 *
 *  反转指定范围的元素
 *  beg 开始迭代器
 *  end 结束迭代器
 */
void printVector(int v){
    cout << v << " ";
}
void test01() {
    vector<int> v{1, 2, 3, 4, 5, 6, 0};
    for_each(v.begin(),v.end(),printVector);    //1 2 3 4 5 6 0
    cout << endl;
    //反转
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),printVector);    //0 6 5 4 3 2 1
    cout << endl;
}

int main() {
    test01();
    return 0;
}
