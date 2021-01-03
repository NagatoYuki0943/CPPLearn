#include <iostream>
#include <map>

using namespace std;

/**
 * map查找和统计
 *  对map容器进行查找数据以及统计数据
 * 函数原型：
 *  find(key);          //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end(); end()代表最后一个数据的下一个
 *                      //multimap找到多个值返回第一个
 *  count(key);         //统计key的元素个数,map键值不允许重复,结果是0或者1,对于multimap会有其他值
 */
void test01() {
    map<int, int> m{make_pair(0, 458)};
    m.insert(make_pair(0, 15));
    m.insert(make_pair(1, 15));
    m.insert(make_pair(2, 12));
    m.insert(make_pair(3, 21));
    m.insert(make_pair(4, 23));
    //查找
    map<int, int>::iterator res = m.find(0);
    if (res != m.end()) {
        cout << res->first << " " << res->second << endl;       //0 458
    } else {
        cout << "NULL" << endl;
    }
    res = m.find(9);
    if (res != m.end()) {
        cout << res->first << " " << res->second << endl;
    } else {
        cout << "NULL" << endl;                                 //NULL
    }

    //统计
    int count = m.count(0);
    cout << "count is " << count << endl;       //count is 1
    count = m.count(7);
    cout << "count is " << count << endl;       //count is 0

    multimap<int, int> mm{make_pair(0, 458), make_pair(0, 15), make_pair(1, 15), make_pair(2, 12), make_pair(3, 21)};
    count = mm.count(0);
    cout << "count is " << count << endl;                   //count is 2
    multimap<int, int>::iterator res1 = mm.find(0);      //总数是2,但是查找时返回的只返回了第一个
    cout << res1->first << " " << res1->second << endl;     //0 458

}

int main() {
    test01();
    return 0;
}
