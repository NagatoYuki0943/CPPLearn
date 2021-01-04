#include <iostream>
#include <set>

using namespace std;

/**
 * set插入和删除
 * set容器进行插入数据和删除数据
 * 函数原型：
 *  insert(elem);           //在容器中插入元素。
 *  insert(operator beg,operator end);  beg和end可以使用 ++ -- ,不能使用 +1 -1   set和map不支持随机访问
 *
 *  erase(pos);             //删除pos迭代器所指的元素，返回下一个元素的迭代器。
 *  erase(operator beg,operator end);  //beg和end可以使用 ++ -- ,不能使用 +1 -1  set和map不支持随机访问
 *                          //删除区间(beg,end)的所有元素 ，返回下一个元素的迭代器。
 *  erase(elem);            //删除容器中值为elem的元素。
 *
 *  clear();                //清除所有元素
 */

void printSet(const set<int> &s) {
    for (set<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    set<int> s1;
    s1.insert(10);
    s1.insert(0);
    s1.insert(10);
    s1.insert(5);
    s1.insert(4);
    s1.insert(2);
    s1.insert(55);

    printSet(s1);       //0 2 4 5 10 55

    //删除
    s1.erase(s1.begin());
    printSet(s1);       //2 4 5 10 55

    //insert 区间
    set<int> s2;
    s2.insert(++s1.begin(), s1.end());
    printSet(s2);       //4 5 10 55

    s2.erase(4);
    printSet(s2);       //5 10 55

    s2.erase(++s2.begin(), --s2.end());
    printSet(s2);       //5 55

    s2.clear();
    printSet(s2);       //null

}

int main() {
    test01();
    return 0;
}
