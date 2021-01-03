#include <iostream>
#include <set>

using namespace std;

/**
 * set和multiset区别
 * 区别：
 *  set不可以插入重复数据，而multiset可以
 *  set插入数据的同时会返回插入结果，表示插入是否成功
 *  multiset不会检测数据，因此可以插入重复数据
 */

void printMultiset(const multiset<int> &s) {
    for (multiset<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s1;

    //set插入有返回值
    pair<set<int>::iterator, bool> res = s1.insert(0);

    //res.second 查看上面的 bool 值
    if (res.second) {
        cout << "successful" << endl;       //successful
    } else {
        cout << "failed" << endl;
    }

    //第二次插入失败
    res = s1.insert(0);

    //res.second 查看上面的 bool 值
    if (res.second) {
        cout << "successful" << endl;
    } else {
        cout << "failed" << endl;           //failed
    }

    //允许插入重复的值
    multiset<int> ms1{3, 3, 4, 4, 1, 1, 55,};
    printMultiset(ms1); //1 1 3 3 4 4 55  有重复的值

}

int main() {
    test01();
    return 0;
}
