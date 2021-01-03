#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * replace_if
 * 功能描述:
 *  将区间内满足条件的元素，替换成指定元素
 * 函数原型：
 *  replace_if(iterator beg, iterator end, _pred, newvalue);
 *
 *  按条件替换元素，满足条件的替换成指定元素
 *  beg 开始迭代器
 *  end 结束迭代器
 *  _pred 函数或谓词
 *  newvalue 替换的新元素
 */
//打印函数
void printVector(int v) {
    cout << v << " ";
}

//替换判断函数
bool greaterFive(int v) {
    return v > 5;
}

//替换判断仿函数
class Greater5 {
public:
    bool operator()(int v) {
        return v > 5;
    }
};

void test01() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //打印
    for_each(v.begin(),v.end(),printVector);    //1 2 3 4 5 6 7 8 9
    cout << endl;
    //条件替换
    //使用函数
    //replace_if(v.begin(),v.end(),greaterFive,0);
    //使用仿函数
    replace_if(v.begin(),v.end(),Greater5(),0);


    for_each(v.begin(),v.end(),printVector);    //1 2 3 4 5 0 0 0 0
    cout << endl;
}

int main() {
    test01();
    return 0;
}
