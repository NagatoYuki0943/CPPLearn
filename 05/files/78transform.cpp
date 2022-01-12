#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
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
 */
//搬运函数
int Trans(int v) {
    return v + 1;
}

//搬运仿函数
class Transform {
public:
    int operator()(int v) {
        return v + 1;
    }
};

//打印仿函数
class MyPrint {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

void test01() {
    vector<int> v1{1, 5, 2, 6, 4, 2, 1, 4, 5};

    vector<int> v2;
    //搬运前要将v2的空间增大
    v2.resize(v1.size());
    //搬运
    //使用函数
    //transform(v1.begin(), v1.end(), v2.begin(), Trans);
    //使用仿函数
    transform(v1.begin(), v1.end(), v2.begin(), Transform());

    for_each(v1.begin(), v1.end(), MyPrint());    //1 5 2 6 4 2 1 4 5
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());    //2 6 3 7 5 3 2 5 6
    cout << endl;
}

int main() {
    test01();
    return 0;
}
