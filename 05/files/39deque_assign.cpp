#include <iostream>
#include <deque>

using namespace std;

/**
 *deque赋值操作
 * 给deque容器进行赋值
 * 函数原型：
 *  deque& operator=(const deque &deq);         //重载等号操作符
 *      直接用 = {值1,值2,值3,...} 也可以
 *  assign(iterator beg, iterator end);         //将[beg, end)区间中的数据拷贝赋值给本身。
 *  assign(n, elem);                            //将n个elem拷贝赋值给本身。
 *
 * 总结：deque赋值操作也与vector相同，需熟练掌握
 */

template<typename T>
void printDeque(const deque<T> d) {
    //常量模板前面要加上typename
    for (typename deque<T>::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1{1, 2, 3, 4, 5};
    deque<int> d2 = d1;
    printDeque<int>(d2);    //1 2 3 4 5

    //直接用 = {值1,值2,值3,...} 也可以
    d2 = {6, 7, 8, 5};
    printDeque(d2);         //6 7 8 5

    deque<int> d3;
    //d3.assign(d2);     直接将另一个deque放入会报错


    deque<int> d4;
    d4.assign(d1.begin(), d1.end() - 1);
    printDeque<int>(d4);    //1 2 3 4

    deque<int> d5;
    d5.assign(5, 55);
    printDeque(d5);         //55 55 55 55 55
}

int main() {
    test01();
    return 0;
}

