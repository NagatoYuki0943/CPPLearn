#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * 算法主要是由头文件<algorithm> <functional> <numeric>组成
 * <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
 * <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
 * <functional>定义了一些模板类,用以声明函数对象。
 *
 * for_each
 * 实现遍历容器
 * 函数原型：
 * for_each(iterator beg, iterator end, _func);
 *   遍历算法 遍历容器元素
 *   beg 开始迭代器
 *   end 结束迭代器
 *   _func 函数或者函数对象
 */

//普通函数,参数是vector中的一个值
void print01(int val) {
    cout << val << " ";
}

//仿函数,参数是vector中的一个值
//void print01(int val){
class print02 {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test01() {
    vector<int> v{1, 4, 3, 6, 5};
    for (int i = 0; i < 5; ++i) {
        v.push_back(i + 10);
    }

    //使用普通函数
    for_each(v.begin(), v.end(), print01);        //1 4 3 6 5 10 11 12 13 14
    cout << endl;

    //仿函数,使用函数对象,这里使用的是匿名函数
    for_each(v.begin(), v.end(), print02());    //1 4 3 6 5 10 11 12 13 14
    cout << endl;
}

int main() {
    test01();
    return 0;
}
