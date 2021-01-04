#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * map大小和交换
 *  统计map容器大小以及交换map容器
 * 函数原型：
 *  empty();       //判断容器是否为空
 *  size();        //返回容器中元素的数目
 *  swap(st);      //交换两个集合容器
 */
void printMap(const map<string, int> &m) {
    for (map<string, int>::const_iterator i = m.begin(); i != m.end(); ++i) {
        cout << (*i).first << " " << (*i).second << " | ";
    }
    cout << endl;
}

void test01() {
    map<string, int> m1{pair<string, int>("A", 1), pair<string, int>("B", 2), pair<string, int>("C", 3)};

    if (m1.empty()) {
        cout << "m1 is empty" << endl;
    } else {
        cout << "m1 is not empty, size is " << m1.size() << endl;   //m1 is not empty, size is 3
    }

    map<string, int> m2{pair<string, int>("C", 4), pair<string, int>("D", 5), pair<string, int>("E", 6)};
    printMap(m1);   //A 1 | B 2 | C 3 |
    printMap(m2);   //C 4 | D 5 | E 6 |

    //交换
    m1.swap(m2);
    printMap(m1);   //C 4 | D 5 | E 6 |
    printMap(m2);   //A 1 | B 2 | C 3 |
}

int main() {
    test01();
    return 0;
}
