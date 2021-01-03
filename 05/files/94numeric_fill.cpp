#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * fill
 * 功能描述：
 *  向容器中填充指定的元素
 * 函数原型：
 *  fill(iterator beg, iterator end, value);
 *
 *  向容器中填充元素
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 填充的值
 */
void printVector(int v){
    cout << v << " ";
}
void test01() {
    vector<int> v{1, 2, 3, 4, 5};
    for_each(v.begin(),v.end(),printVector);        //1 2 3 4 5
    cout << endl;

    fill(v.begin(),--v.end(),9);

    for_each(v.begin(),v.end(),printVector);        //9 9 9 9 5
    cout << endl;
}

int main() {
    test01();
    return 0;
}
