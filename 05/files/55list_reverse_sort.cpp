#include <iostream>
#include <list>

using namespace std;

/**
 * list 反转和排序
 *  将容器中的元素反转，以及将容器中的数据进行排序
 * 函数原型：
 *  l1.reverse();   //反转链表
 *  l1.sort();      //链表排序,默认升序
 *
 *  所有不支持随机访问的迭代器不可以用标准的算法,如algorithm中的排序
 *  但是容器内部提供了一些算法,如l1.reverse() 和 l1.sort()
 */
void printList(const list<int> &l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

//降序函数
bool myCompare(int a, int b) {
    //降序,让第一个数大于第二个数
    return a > b;
}

void test01() {
    list<int> l1{1, 2, 3, 4, 5};
    l1.push_front(0);
    l1.push_back(6);
    printList(l1);      //0 1 2 3 4 5 6

    //反转
    l1.reverse();
    printList(l1);      //6 5 4 3 2 1 0

    list<int> l2{4, 1, 1, 2, 53, 56, 48, 12, 24};
    //排序,默认升序
    l2.sort();
    printList(l2);      //1 1 2 4 12 24 48 53 56
    //降序
    l2.sort(myCompare);
    printList(l2);      //56 53 48 24 12 4 2 1 1
}

int main() {
    test01();
    return 0;
}
