#include <iostream>
#include <list>

using namespace std;

/**
 * list构造函数
 * 创建list容器
 * 函数原型：
 *  list<T> lst;                //list采用采用模板类实现,对象的默认构造形式：
 *  list(iterator beg,iterator end);              //构造函数将[beg, end)区间中的元素拷贝给本身。
 *  list(n,elem);               //构造函数将n个elem拷贝给本身。
 *  list(const list &lst);      //拷贝构造函数
 *   = {值1,值2,值3,...}  构造
 */
void printList(const list<int> &l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    //默认构造
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    printList(l1);      //1 2 3 4 5

    // = {值1,值2,值3,...}  构造
    list<int> l2{9, 8, 7, 6, 5};
    printList(l2);      //9 8 7 6 5

    //区间构造
    list<int> l3(l1.begin(), l1.end());
    printList(l3);      //1 2 3 4 5

    //(l1.begin() + 1, l1.end() - 1) 会报错,vector和deque可以这样,list用的是指针,这样写是错误的
    //list<int> l5(l1.begin() + 1, l1.end());

    //拷贝构造
    list<int> l4(l3);
    printList(l4);      //1 2 3 4 5


    //n个elem
    list<int> l5(5, 999);
    printList(l5);      //999 999 999 999 999
}

int main() {
    test01();
    return 0;
}
