#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * replace
 * 功能描述：
 *  将容器内指定范围的旧元素修改为新元素  所有元素都替换
 * 函数原型：
 *  replace(iterator beg, iterator end, oldvalue, newvalue);
 *  将区间内旧元素 替换成 新元素
 *  beg 开始迭代器
 *  end 结束迭代器
 *  oldvalue 旧元素
 *  newvalue 新元素
 */
//打印仿函数
class PrintVector{
public:
    void operator()(int v){
        cout << v << " ";
    }
};
void test01() {
    vector<int> v{0, 1, 2, 3, 1, 4, 5, 7, 8, 1};
    for_each(v.begin(),v.end(),PrintVector());          //0 1 2 3 1 4 5 7 8 1
    cout  << endl;
    //替换
    replace(v.begin(),v.end(),1,9);
    for_each(v.begin(),v.end(),PrintVector());          //0 9 2 3 9 4 5 7 8 9   1 全部变为 9
    cout  << endl;
}

int main() {
    test01();
    return 0;
}
