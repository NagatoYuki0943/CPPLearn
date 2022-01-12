#include <iostream>
#include <deque>

using namespace std;

/**
 * deque大小操作
 * 对deque容器的大小进行操作
 * 函数原型
 *  deque.empty();                  //判断容器是否为空  为空返回 TRUE,为假返回FALSE
 *
 *      注意,deque没有capacity,只有size
 *  deque.size();                   //返回容器中元素的个数
 *  deque.resize(num);              //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
 *		                            //如果容器变短，则末尾超出容器长度的元素被删除。
 *  deque.resize(num, elem);        //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
 *                                  //如果容器变短，则末尾超出容器长度的元素被删除。
 *
 */

void printDeque(const deque<int> deque1) {
    for (deque<int>::const_iterator it = deque1.begin(); it != deque1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    deque<int> d1;
    bool res = d1.empty();
    cout << "res = " << res << endl;    //res = 1

    d1 = {1, 2, 3, 4, 5};
    cout << "d1's size is " << d1.size() << endl;   //d1's size is 5

    d1.resize(10);
    cout << "d1's size is " << d1.size() << endl;   //d1's size is 10
    printDeque(d1);                                 //1 2 3 4 5 0 0 0 0 0

    d1.resize(15, 9);
    cout << "d1's size is " << d1.size() << endl;   //d1's size is 15
    printDeque(d1);                                 //1 2 3 4 5 0 0 0 0 0 9 9 9 9 9
}

int main() {
    test01();
    return 0;
}
