#include <iostream>
#include <deque>

using namespace std;

/**
 * deque 数据存取:
 *  对deque 中的数据的存取操作
 * 函数原型：
 *  operator[];      //返回索引idx所指的数据
 *  at(int idx);     //返回索引idx所指的数据
 *  front();         //返回容器中第一个数据元素
 *  back();          //返回容器中最后一个数据元素
 *
 */

template<typename T>
void printDeque(const deque<T> d) {
    for (int i = 0; i < d.size(); ++i) {
        //[] 和 at 效果相同
        cout << d[i] << "-" << d.at(i) << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1{1, 2, 3, 4, 5};
    cout << d1.front() << " " << d1.back() << endl; //1 5
    printDeque(d1);                                 //1-1 2-2 3-3 4-4 5-5
}

int main() {
    test01();
    return 0;
}
