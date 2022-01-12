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
 *  set& operator=(const set &st);      //重载等号操作符
 *  没有assign()方法
 *  也没有push和pop方法,要使用insert插入,erase,clear删除
 *
 *  insert erase clear
 *  empty size
 *  swap
 *  find 查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end(); end()代表最后一个数据的下一个
 *  count 统计key的元素个数,set不允许重复,结果是0或者1,对于multiset会有其他值
 */

void printSet(set<int> &s){
    for(auto &i: s){
        cout << i << " ";
    }
    cout << endl;
}

void test1(){
    set<int> s1 = {1, 2, 2, 9, 10, -5};
    printSet(s1);                               //-5 1 2 9 10
    set<int> s2(s1);
    set<int> s3(s1.begin(), s1.end()--);
    set<int> s3_1 = s3;

    cout << s3.empty() << " " << s3.size() << endl;//0 5

    set<int> s4 {10};
    s4.swap(s1);
    printSet(s1);   //10
    printSet(s4);   //-5 1 2 9 10

    cout << s4.count(9) << endl;    //1
}

//仿函数
class MyCompare{
public:
    //成员函数后加const我们称为这个函数为常函数,常函数不可以修改成员函数
    bool operator()(int a, int b) const{
        //降序
        return a > b;
    }
};

void test2(){
    set<int, MyCompare> s1 = {1, 2, 2, 9, 10, -5};
    for (set<int, MyCompare>::iterator i = s1.begin(); i != s1.end(); ++i) {
        cout << *i << " ";
    }
    //10 9 2 1 -5
    cout << endl;
}


int main(){
    //test1();
    test2();
    return 0;
}