#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 常用拷贝和替换算法
 * 学习目标：
 *  掌握常用的拷贝和替换算法
 * 算法简介：
 *  copy                // 容器内指定范围的元素拷贝到另一容器中
 *  replace             // 将容器内指定范围的旧元素修改为新元素
 *  replace_if          // 容器内指定范围满足条件的元素替换为新元素
 *  swap                // 互换两个容器的元素
 *
 * copy
 * 功能描述：
 *  容器内指定范围的元素拷贝到另一容器中
 * 函数原型：
 *  copy(iterator beg, iterator end, iterator dest);
 *
 *  按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 *  beg  开始迭代器
 *  end  结束迭代器
 *  dest 目标起始迭代器
 *
 * transform
 * 功能描述：
 *  搬运容器到另一个容器中
 * 函数原型：
 *  transform(iterator beg1, iterator end1, iterator beg2, _func);
 *  beg1 源容器开始迭代器
 *  end1 源容器结束迭代器
 *  beg2 目标容器开始迭代器
 *  _func 函数或者函数对象
 *
 *  用的不多,不如直接使用 =
 */
void printVector(int v) {
    cout << v << " ";
}

void test01() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{6, 7, 8, 9, 10};
    vector<int> v3;
    v3.resize(v1.size() + 1);

    copy(v1.begin() + 1, v1.end(), v3.begin());
    for_each(v2.begin(), v2.end(), printVector);  //2 3 4 5 10    只替换了4个,最后一个还是原值
    cout << endl;

    copy(v1.begin() + 1, v1.end(), v2.begin());
    for_each(v3.begin(), v3.end(), printVector);  //2 3 4 5 0 0   只替换了4ge,剩下的值自动补0
    cout << endl;
}

int main() {
    test01();
    return 0;
}
