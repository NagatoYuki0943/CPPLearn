#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * binary_search
 *  查找指定元素是否存在
 * 函数原型：
 * bool binary_search(iterator beg, iterator end, value);
 *  查找指定的元素，查到 返回true  否则false
 *  注意: 在无序序列中不可用 如:1,3,4,5,6,2
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 查找的元素
 */
void test01() {
    vector<int> v{1, 2, 3, 5, 6, 7, 8};
    bool res = binary_search(v.begin(), v.end(), 4);
    cout << res << endl;    //0
    res = binary_search(v.begin(), v.end(), 5);
    cout << res << endl;    //1

    //无序序列可能查得到
    vector<int> v1{1, 3, 4, 5, 6, 2};
    res = binary_search(v1.begin(), v1.end(), 2);
    cout << res << endl;    //0 无序序列可能查不到
}

int main() {
    test01();
    return 0;
}
