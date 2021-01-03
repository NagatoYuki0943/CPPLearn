#include <iostream>
#include <list>

using namespace std;

/**
 * list 插入和删除
 * 函数原型：
 *  push_back(elem);         //在容器尾部加入一个元素
 *  pop_back();              //删除容器中最后一个元素
 *  push_front(elem);        //在容器开头插入一个元素
 *  pop_front();             //从容器开头移除第一个元素
 *
 *  insert(iterator pos,elem);                  //在pos位置插elem元素的拷贝，返回新数据的位置。
 *                                              //不能让l1.begin() + 1,但是可以使用 ++ / -- ,如++l1.begin(),--l1.end()
 *  insert(iterator pos,n,elem);                //在pos位置插入n个elem数据，无返回值。
 *  insert(iterator pos,iterator beg,iterator end);  //在pos位置插入[beg,end)区间的数据，无返回值。
 *
 *  erase(iterator pos);                        //删除pos位置的数据，返回下一个数据的位置。
 *  erase(iterator beg,iterator end);           //删除[beg,end)区间的数据，返回下一个数据的位置。
 *  clear();                 //移除容器的所有数据
 *
 *  remove(elem);            //删除容器中所有与elem值匹配的元素。
 */
void printList(const list<int> l) {
    for (list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

//push/pop front/back
void test01() {
    list<int> l1;
    //尾插
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    //头插
    l1.push_front(4);
    l1.push_front(5);
    l1.push_front(6);
    printList(l1);      //6 5 4 1 2 3

    //头删和尾删
    l1.pop_front();
    l1.pop_back();
    printList(l1);      //5 4 1 2
    cout << "-----------------------" << endl;
}

//insert
void test02() {
    list<int> l1{5, 5, 5};
    printList(l1);      //5 5 5

    //不能让l1.begin() + 1,但是可以使用 ++ / -- ,如++l1.begin(),--l1.end()
    l1.insert(++l1.begin(), 4);
    l1.insert(--l1.end(), 4, 2);
    printList(l1);      //5 4 5 2 2 2 2 5

    l1.insert(l1.end(), 3, 88);
    printList(l1);      //5 4 5 2 2 2 2 5 88 88 88
    cout << "-----------------------" << endl;
}

//erase clear
void test03() {
    list<int> l1{4, 2, 56, 2, 1, 8, 2, 3};
    //删除第二个
    l1.erase(++l1.begin());
    printList(l1);      //4 56 2 1 8 2 3    没有2了
    //删除第二个到倒数第二个
    l1.erase(++l1.begin(), --l1.end());
    printList(l1);      //4 3  只有第一个和最后一个了

    list<int> l2{1, 2, 3, 2, 4, 2, 5, 2, 6};
    //移除所有的2
    l2.remove(2);
    printList(l2);  //1 3 4 5 6

    //清空
    l2.clear();
    printList(l2);  //空
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}
