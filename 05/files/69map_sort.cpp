#include <iostream>
#include <map>

using namespace std;

/**
 * map容器排序
 *  map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
 * 主要技术点:
 *  利用仿函数，可以改变排序规则
 */

class MyCompare {
public:
    //重载() 加上const才不会报错
    //成员函数后加const我们称为这个函数为常函数,常函数不可以修改成员函数
    bool operator()(int v1, int v2) const  {
        //降序
        return v1 > v2;
    }
};

void printMap(const map<int, int, MyCompare> m) {
    for (map<int, int, MyCompare>::const_iterator i = m.begin(); i != m.end(); ++i) {
        cout << i->first << " " << i->second << " | ";
    }
    cout << endl;
}

void test01() {
    map<int, int, MyCompare> m{make_pair(1, 85), make_pair(9, 4), make_pair(3, 25),};
    m.insert(pair<int, int>(6, 451));
    m.insert(pair<int, int>(8, 1));
    m.insert(make_pair(4, 51));
    m.insert(make_pair(2, 50));

    //默认键值从小到大
    printMap(m);    //1 85 | 2 50 | 3 25 | 4 51 | 6 451 | 8 1 | 9 4 |


}

int main() {
    test01();
    return 0;
}
