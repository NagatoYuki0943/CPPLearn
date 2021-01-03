#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/**
 * 常用排序算法
 * 学习目标：
 *  掌握常用的排序算法
 * 算法简介：
 *  sort               //对容器内元素进行排序
 *  random_shuffle     //洗牌   指定范围内的元素随机调整次序
 *  merge              //容器元素合并，并存储到另一容器中
 *  reverse            //反转指定范围的元素
 *
 * sort
 *  对容器内元素进行排序
 * 函数原型：
 *  sort(iterator beg, iterator end, _Pred);
 *
 *  按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 *  beg    开始迭代器
 *  end    结束迭代器
 *  _Pred  谓词
 */

//打印仿函数
class PrintList {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

//函数

void test01() {
    vector<int> l{1, 3, 5, 2, 4, 0, 6};

    //升序
    sort(l.begin(), l.end());

    for_each(l.begin(), l.end(), PrintList());    //0 1 2 3 4 5 6
    cout << endl;
    //降序,第三个参数 是大于,可以自己写,也可以用系统内置的
    sort(l.begin(), l.end(), greater<int>());
    for_each(l.begin(), l.end(), PrintList());    //6 5 4 3 2 1 0
    cout << endl;
}

int main() {
    test01();
    return 0;
}
