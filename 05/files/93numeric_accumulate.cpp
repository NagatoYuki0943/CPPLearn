#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * 常用算术生成算法
 * 学习目标：
 *  掌握常用的算术生成算法
 * 注意：
 *  算术生成算法属于小型算法，使用时包含的头文件为 `#include <numeric>
 * 算法简介：
 *  accumulate       // 计算容器元素累计总和
 *  fill             // 向容器中添加元素
 *
 * accumulate
 * 功能描述：
 *  计算区间内 容器元素累计总和
 * 函数原型：
 *  accumulate(iterator beg, iterator end, value);
 *  计算容器元素累计总和
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 起始值累加值,一般为0
 */

void test01() {
    list<int> l;
    for (int i = 0; i < 101; ++i) {
        l.push_back(i);
    }

    //第三个值是初始值
    int sum = accumulate(l.begin(), l.end(), 0);
    cout << sum << endl;    //5050

    //1000 + 5050 = 6050
    sum = accumulate(l.begin(), l.end(), 1000);
    cout << sum << endl;    //6050
}

int main() {
    test01();
    return 0;
}
