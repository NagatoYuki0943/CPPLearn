#include <iostream>
#include <set>

using namespace std;

/**
 * set查找和统计
 *  对set容器进行查找数据以及统计数据
 * 函数原型：
 *  find(key);          //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end(); end()代表最后一个数据的下一个
 *                      //multiset()找到多个返回第一个
 *  count(key);         //统计key的元素个数,set不允许重复,结果是0或者1,对于multiset会有其他值
 */

void test01() {
    set<int> s1;
    s1.insert(0);
    s1.insert(0);
    s1.insert(1);
    s1.insert(12);
    s1.insert(10);
    s1.insert(4);
    set<int>::iterator res1 = s1.find(1);
    if (res1 != s1.end()) {
        cout << *res1 << endl;                  //1
    } else {
        cout << "couldn't found 1 " << endl;
    }
    set<int>::iterator res2 = s1.find(6);
    if (res2 != s1.end()) {
        cout << *res2 << endl;
    } else {
        cout << "couldn't found 6 " << endl;    //couldn't found 6
    }
}

//统计
void test02() {
    set<int> s1{1, 0, 45, 2, 1, 8, 6, 864, 457, 21, 5};
    int number = s1.count(1);
    cout << "count 1 is " << number << endl;    //count 1 is 1
    number = s1.count(11);
    cout << "count 11 is " << number << endl;   //count 1 is 1


    multiset<int> ms{1, 0, 45, 2, 1, 8, 6, 864, 457, 21, 5};
    number = ms.count(1);
    cout << "count is " << number << endl;    //count is 2
    multiset<int>::iterator res = ms.find(1);   //找到两个,返回第一个
    cout << *res << endl;   //1

}

int main() {
    test01();
    test02();
    return 0;
}
