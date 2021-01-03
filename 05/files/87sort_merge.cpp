#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/**
 * merge
 *  两个容器元素合并，并存储到另一容器中
 * 函数原型：
 *  merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 *
 *  容器元素合并，并存储到另一容器中
 *  注意: 两个容器必须是有序的,顺序必须一致,合并完之后结果是有序的,不然合并完结果是无序的
 *  beg1   容器1开始迭代器
 *  end1   容器1结束迭代器
 *  beg2   容器2开始迭代器
 *  end2   容器2结束迭代器
 *  dest   目标容器开始迭代器
 */

//打印仿函数
class PrintDeque {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

//有序
void test01() {
    deque<int> d1{1, 3, 4, 5, 9, 10};
    deque<int> d2{0, 1, 2, 5, 6, 8, 9};
    deque<int> d3;
    d3.resize(d1.size() + d2.size());
    //源1.开始,源1.结束,源2.开始,源2.结束,目标容器开始
    merge(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());

    for_each(d3.begin(), d3.end(), PrintDeque());     //0 1 1 2 3 4 5 5 6 8 9 9 10
    cout << endl;
}

//无序
void test02() {
    deque<int> d1{2, 5, 3, 1};
    deque<int> d2{1, 2, 3, 4};
    deque<int> d3;
    d3.resize(d1.size() + d2.size());
    //源1.开始,源1.结束,源2.开始,源2.结束,目标容器开始
    merge(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());

    for_each(d3.begin(), d3.end(), PrintDeque());     //1 2 2 3 4 5 3 1    结果是无序的
    cout << endl;
}

int main() {
    test01();
    cout << "---------------------------------" << endl;
    test02();
    return 0;
}
