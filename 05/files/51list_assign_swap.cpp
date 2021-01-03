#include <iostream>
#include <list>

using namespace std;

/**
 * list 赋值和交换
 *  给list容器进行赋值，以及交换list容器
 * 函数原型：
 *  list& operator=(const list &lst);   //重载等号操作符
 *  assign(iterator beg, iterator end); //将[beg, end)区间中的数据拷贝赋值给本身。
 *                                      //不能让 l2.begin() + 1,但是可以使用 ++或者--,如++l2.begin()
 *  assign(n, elem);                    //将n个elem拷贝赋值给本身。
 *  swap(lst);                          //将lst与本身的元素互换。
 */
void printList(const list<int> &l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

//赋值
void test01() {
    list<int> l1{8, 8, 8, 8, 8};
    printList(l1);      //8 8 8 8 8

    list<int> l2 = l1;
    printList(l2);      //8 8 8 8 8

    list<int> l3;
    //l3.assign(l2);    不能直接将另一个list放进去,会报错

    //不能让 l2.begin() + 1,但是可以使用 ++或者--,如++l2.begin()
    l3.assign(++l2.begin(), --l2.end());
    printList(l3);      //8 8 8

    // n个 val
    list<int> l4;
    l4.assign(10, 45);
    printList(l4);      //45 45 45 45 45 45 45 45 45 45
}

//交换
void test02() {
    list<int> l1{8, 8, 8, 8, 8};
    list<int> l2{9, 9, 9, 9, 9, 9, 9, 9};
    cout << "before swap l1 : ";   //before swap l1 : 8 8 8 8 8
    printList(l1);
    cout << "before swap l2 : ";   //before swap l2 : 9 9 9 9 9 9 9 9
    printList(l2);

    l1.swap(l2);

    cout << "after swap l1 : ";    //after swap l1 : 9 9 9 9 9 9 9 9
    printList(l1);
    cout << "after swap l2 : ";    //after swap l2 : 8 8 8 8 8
    printList(l2);
}

int main() {
    test01();
    test02();
    return 0;
}
