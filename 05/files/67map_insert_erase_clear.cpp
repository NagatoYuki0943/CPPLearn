#include <iostream>
#include <string>
#include <map>

using namespace std;

/**
 * map插入和删除
 *  map容器进行插入数据和删除数据
 * 函数原型：
 *  insert(elem);                           //在容器中插入元素。
 *
 *  erase(iterator pos);                    //删除pos迭代器所指的元素，返回下一个元素的迭代器。
 *  erase(iterator beg,iterator end);       //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。 beg和end可以++,--,不能+1,-1,不支持随机访问
 *
 *  erase(key);                             //删除容器中值为key的元素。
 *
 *  clear();                                //清除所有元素
 */
void printMap(const map<string, int> &m) {
    for (map<string, int>::const_iterator i = m.begin(); i != m.end(); ++i) {
        cout << i->first << " " << i->second << " | ";
    }
    cout << endl;
}

void test01() {
    map<string, int> m1;

    //插入方式1
    m1.insert(pair<string, int>("A", 1));

    //插入方式2 建议这个
    m1.insert(make_pair("B", 2));

    //插入方式3,使用值类型
    m1.insert(map<string, int>::value_type("C", 3));

    //插入方式3
    m1["D"] = 4;

    cout << m1["D"] << endl;    //4
    cout << m1["E"] << endl;    //0

    printMap(m1);       //A 1 | B 2 | C 3 | D 4 | E 0 | 最后一个是查找的时候找到的,second默认是0


    //删除
    m1.erase(m1.begin());
    printMap(m1);       //B 2 | C 3 | D 4 | E 0 |   第一个没了

    //删除 k = B的值
    m1.erase("B");
    printMap(m1);       //C 3 | D 4 | E 0 |         k=B的被删除了

    //删除区间
    m1.erase(++m1.begin(),--m1.cend());
    printMap(m1);       //C 3 | E 0 |

    m1.clear();
    printMap(m1);       //空
}

int main() {
    test01();
    return 0;
}
