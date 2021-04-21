#include <iostream>
#include <set>

using namespace std;

/**
 * set容器排序
 *  set容器默认排序规则为从小到大，掌握如何改变排序规则
 * 主要技术点：
 *  利用仿函数，可以改变排序规则
 */

void printSet(const set<int> &s) {
    for (set<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}


class MyCompare {
public:
    //重载小括号,改为降序 加上const才不会报错
    bool operator()(int a, int b) const {
        return a > b;
    }
};

void test01() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);
    //默认升序
    printSet(s1);       //10 20 30 40 50

    //使用仿函数
    set<int, MyCompare> s2;
    //默认升序
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test01();
    return 0;
}
