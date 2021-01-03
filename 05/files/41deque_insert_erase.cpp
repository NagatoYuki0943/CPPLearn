#include <iostream>
#include <deque>

using namespace std;

/**
 * deque 插入和删除
 * 向deque容器中插入和删除数据
 *
 * 函数原型：
 * 两端插入操作：  vector只有back没有front操作
 *  push_back(elem);            //在容器尾部添加一个数据
 *  push_front(elem);           //在容器头部插入一个数据
 *  pop_back();                 //删除容器最后一个数据
 *  pop_front();                //删除容器第一个数据
 *
 * 指定位置操作：
 *  insert(const_iterator pos,elem);                //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
 *  insert(const_iterator pos,n,elem);              //在pos位置插入n个elem数据，无返回值。
 *  insert(const_iterator pos,const_iterator beg,const_iterator end);
 *                                                 //在pos位置插入[beg,end)区间的数据，无返回值。
 *
 *  erase(const_iterator pos);                      //删除pos位置的数据，返回下一个数据的位置。
 *  erase(const_iterator beg,const_iterator end);   //删除[beg,end)区间的数据，返回下一个数据的位置。
 *  clear();                                        //清空容器的所有数据
 */

void prinfDeque(const deque<int> d) {
    for (deque<int>::const_iterator i = d.begin(); i != d.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1{5, 4, 6, 2, 8};
    //前后添加
    d1.push_front(0);
    d1.push_back(1);
    prinfDeque(d1);    //0 5 4 6 2 8 1

    //前后删除
    d1.pop_front();
    d1.pop_back();
    prinfDeque(d1);    //5 4 6 2 8
    cout << "--------------------" << endl;
}

void test02() {
    deque d1{1, 2, 3, 4, 5};
    //头插
    d1.insert(d1.begin() + 1, 99);
    prinfDeque(d1);     //1 99 2 3 4 5          头部多了 1
    //尾插
    d1.insert(d1.end(), 2, 12);
    prinfDeque(d1);     //1 99 2 3 4 5 12 12    尾部多了两个 12

    deque<int> d2{1, 1};
    //插入一个deque区间
    d1.insert(d1.end(), d2.begin(), d2.end());
    prinfDeque(d1);     //1 99 2 3 4 5 12 12 1 1    多了d2的数据
    cout << "--------------------" << endl;
}

void test03() {
    deque<int> d1{1, 2, 3, 4, 5};
    d1.erase(d1.begin() + 1); //删除第二个
    prinfDeque(d1); //1 3 4 5   2没有了

    deque<int> d2{3, 4, 5, 6, 7, 8};
    d2.erase(d2.begin() + 2, d2.end() - 1);
    prinfDeque(d2); //3 4 8    567删除了

    deque<int> d3{1, 2, 3, 4, 5};
    d3.clear();
    prinfDeque(d3); //无
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
