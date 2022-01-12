#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 谓词概念
 * 概念：
 *  返回bool类型的仿函数称为谓词
 *  如果operator()接受一个参数，那么叫做一元谓词
 *  如果operator()接受两个参数，那么叫做二元谓词
 */
class GreaterFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

void test01() {
    vector<int> v{0, 1, 2, 3, 4};
    for (int i = 6; i < 10; ++i) {
        v.push_back(i);
    }
    //查找容器中有没有大于5的数字
    //find_if() 查找存在的内容  参数: 开始,结束,谓词  返回值是 The first iterator ,找不到返回 v.end()

    //使用对象
    GreaterFive greaterFive;
    auto res = find_if(v.begin(), v.end(), greaterFive);
    if (res != v.end()) {
        cout << *res << endl;   //6
    } else {
        cout << "not found" << endl;
    }

    //直接使用匿名对象  GreaterFive()  就是没有对象名的类
    res = find_if(v.begin(), v.end(), GreaterFive());
    if (res != v.end()) {
        cout << *res << endl;   //6
    } else {
        cout << "not found" << endl;
    }
}

int main() {
    test01();
    return 0;
}
