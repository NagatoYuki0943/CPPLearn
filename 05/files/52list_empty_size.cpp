#include <iostream>
#include <list>

using namespace std;

/**
 * list 大小操作
 * 函数原型：
 *  size();                     //返回容器中元素的个数
 *  empty();                    //判断容器是否为空
 *  resize(num);                //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
 *				                //如果容器变短，则末尾超出容器长度的元素被删除。
 *  resize(num, elem);          //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
 *                              //如果容器变短，则末尾超出容器长度的元素被删除。
 */

void printList(const list<int> &l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    list<int> l1{0, 5, 3, 2, 4, 6, 1};
    printList(l1);      //0 5 3 2 4 6 1

    cout << l1.empty() << endl;     //0 不为空
    cout << "l1's size is " << l1.size() << endl;   //l1's size is 7

    //重新指定长度,多的默认是0
    l1.resize(10);
    printList(l1);      //0 5 3 2 4 6 1 0 0 0

    //重新指定长度,多的默认值可以设定
    l1.resize(13, 5);
    printList(l1);      //0 5 3 2 4 6 1 0 0 0 5 5 5

    //重新指定长度,缩短,多余的会删除
    l1.resize(4);
    printList(l1);      //0 5 3 2
}

int main() {
    test01();
    return 0;
}
