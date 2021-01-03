#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * adjacent_find
 * 查找相邻重复元素
 * 函数原型：
 *  adjacent_find(iterator beg, iterator end);
 *  查找相邻重复元素,返回相邻元素的第一个位置的迭代器,没有查到,返回end()
 *  beg 开始迭代器
 *  end 结束迭代器
 */
void test01() {
    vector<int> v{1, 2, 3, 4, 4, 5, 6, 6};

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end()) {
        cout << *pos << " " << *(++pos) << endl;    //4 4
    } else {
        cout << "not found" << endl;
    }
}

int main() {
    test01();
    return 0;
}
