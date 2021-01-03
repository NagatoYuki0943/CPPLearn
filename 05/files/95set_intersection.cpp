#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
/**
 * 常用集合算法
 * 学习目标：
 *  掌握常用的集合算法
 * 算法简介：
 *  set_intersection            // 求两个容器的交集         都在 algorithm 算法合集中
 *  set_union                   // 求两个容器的并集
 *  set_difference              // 求两个容器的差集
 *
 * set_intersection
 *  求两个容器的交集
 * 函数原型：
 *   set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 *   求两个集合的交集
 *   注意:两个集合必须是有序序列,不然获取不到正确的交并集
 *   beg1 容器1开始迭代器
 *   end1 容器1结束迭代器
 *   beg2 容器2开始迭代器
 *   end2 容器2结束迭代器
 *   dest 目标容器开始迭代器
 *   函数返回结束位置的的迭代器
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
    //重新分配目标容器空间,大小按照最大的容量,最特殊的情况,大容器包含了小容器,空间用小空间的值即可
    //min()求最小值
    d3.resize(min(d1.size(), d2.size()));

    //求交集
    //返回结束位置的的迭代器
    deque<int>::iterator end = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
    for_each(d3.begin(), end, PrintDeque());            //3 4 5
    cout << endl;
    for_each(d3.begin(), d3.end(), PrintDeque());       //3 4 5 0 0  最后两个 0 是补足的
    cout << endl;

    cout << "------------------------------------" << endl;
}

//无序列表
void test02() {
    deque<int> d1{1, 2, 0, 3, 5, 8};       //1 2 3 5
    deque<int> d2{5, 0, 3, 2, 6, 1,};
    deque<int> d3;
    //重新分配空间,大小按照最大的容量,最特殊的情况,大容器包含了小容器,空间用小空间的值即可
    //min()求最小值
    d3.resize(min(d1.size(), d2.size()));

    //求交集
    //返回结束位置的的迭代器
    deque<int>::iterator end = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
    for_each(d3.begin(), end, PrintDeque());            //5     结果不对,
    cout << endl;
    for_each(d3.begin(), d3.end(), PrintDeque());       //5 0 0 0 0 0
}

int main() {
    test01();
    test02();
    return 0;
}
