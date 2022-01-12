#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

/**
 * random_shuffle
 * 洗牌   指定范围内的元素随机调整次序
 * 函数原型：
 *  random_shuffle(iterator beg, iterator end);
 *  指定范围内的元素随机调整次序
 *  beg 开始迭代器
 *  end 结束迭代器
 */

//打印函数
void printVector(int v) {
    cout << v << " ";
}

void test01() {
    vector<int> v{1, 2, 3, 4, 5};
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), printVector);    //5 2 4 3 1
}

int main() {
    //生成随机数种子,可以生成不同的随机顺序
    srand((unsigned int) time(NULL));
    test01();
    return 0;
}
