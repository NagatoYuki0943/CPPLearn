#include <iostream>
#include <set>

using namespace std;

/**
 * set/ multiset 容器(集合)
 * set基本概念
 *  所有元素都会在插入时自动被排序
 *
 * 本质：
 *  set/multiset属于关联式容器，底层结构是用二叉树实现。map底层也是二叉树
 *
 * set和multiset区别：
 *  set不允许容器中有重复的元素
 *  multiset允许容器中有重复的元素
 *
 * set构造和赋值
 *  功能描述：创建set容器以及赋值
 *
 * 构造：
 *  set<T> st;                          //默认构造函数：
 *  set(const set &st);                 //拷贝构造函数
 *  set(operator beg,operator end);     //beg和end可以使用 ++ -- ,不能使用 +1 -1
 *                                      //区间拷贝
 *  set<int> s1{5, 2, 1, 1, 5, 6, 9, 8, 2, 1, 2};   = {} 构造
 *
 * 赋值：
 *  set& operator=(const set &st);      //重载等号操作符
 *  没有assign()方法
 *  也没有push和pop方法,要使用insert插入,erase删除
 */
void printSet(const set<int> &s) {
    for (set<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void printMultiset(const multiset<int> &s) {
    for (multiset<int>::const_iterator i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    //默认构造
    set<int> s1{5, 2, 1, 1, 5, 6, 9, 8, 2, 1, 2};
    //使用insert插入,没有push
    s1.insert(5);
    printSet(s1);       //1 2 5 6 8 9  默认排序,重复的数字不存在

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);       //1 2 5 6 8 9


    set<int> s3(++s2.begin(), --s2.end());   //2 5 6 8
    printSet(s3);

    //赋值 =
    set<int> s4;
    s4 = s2;
    printSet(s4);       //1 2 5 6 8 9


    //multiset允许插入重复的值
    multiset<int> ms1{5, 2, 1, 1, 5, 6, 9, 8, 2, 1, 2};
    ms1.insert(5);
    printMultiset(ms1); //1 1 1 2 2 2 5 5 5 6 8 9  默认排序,重复的数字存在
}

int main() {
    test01();
    return 0;
}
