#include <iostream>
#include <set>

using namespace std;

/**
 * set大小和交换
 * 功能描述：
 *  统计set容器大小以及交换set容器
 * 函数原型：
 *  empty();        //判断容器是否为空
 *  size();         //返回容器中元素的数目
 *  没有resize()方法,不能用0填充,会出现重复值
 *  swap(st);       //交换两个集合容器
 */
void printSet(const set<int> &s) {
    for (set<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s1{5, 2, 3, 4, 6, 1, 2, 1};

    //插入数据
    s1.insert(8);
    printSet(s1);       //1 2 3 4 5 6 8

    if (s1.empty()) {
        cout << "s1 is empty" << endl;
    } else {
        cout << "s1 isn't empty" << endl;               //s1 isn't empty
    }

    cout << "s1's size is " << s1.size() << endl;       //s1's size is 7

    set<int> s2{5, 2, 3, 0, 1, 4, 2};

    printSet(s1);       //1 2 3 4 5 6 8
    printSet(s2);       //0 1 2 3 4 5
    //交换
    s1.swap(s2);
    printSet(s1);       //0 1 2 3 4 5
    printSet(s2);       //1 2 3 4 5 6 8

}

int main() {
    test01();
    return 0;
}
