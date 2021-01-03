#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
/**
 * set_union
 *  求两个集合的并集
 * 函数原型：
 *  set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 *
 *  求两个集合的并集
 *  注意:两个集合必须是有序序列
 *  beg1 容器1开始迭代器
 *  end1 容器1结束迭代器
 *  beg2 容器2开始迭代器
 *  end2 容器2结束迭代器
 *  dest 目标容器开始迭代器
 *  函数返回结束位置的的迭代器
 */

//打印仿函数
class PrintDeque {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

void test01() {
    deque<int> d1{1, 2, 3, 4, 5};
    deque<int> d2{3, 4, 5, 6, 7, 8};
    deque<int> d3;
    //重新分配目标容器空间,大小按照最大的容量,最特殊的情况,两者不相交,目标容器大小是两个容器大小之和
    d3.resize(d1.size() + d2.size());

    //求并集
    //返回结束位置的的迭代器
    deque<int>::iterator end = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
    for_each(d3.begin(), end, PrintDeque());            //1 2 3 4 5 6 7 8
    cout << endl;
    for_each(d3.begin(), d3.end(), PrintDeque());       //1 2 3 4 5 6 7 8 0 0 0  最后三个 0 是补足的
    cout << endl;
}

int main() {
    test01();
    return 0;
}
