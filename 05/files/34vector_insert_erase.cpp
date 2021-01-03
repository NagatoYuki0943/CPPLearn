#include <iostream>
#include <vector>

using namespace std;

/**
 * 功能描述：
 *   对vector容器进行插入、删除操作
 * 函数原型：
 *   push_back(elem);                                    //尾部插入元素elem
 *   pop_back();                                         //删除最后一个元素,直接删除,不返回值
 *   insert(const_iterator pos, elem);                   //迭代器指向位置pos插入元素elem
 *   insert(const_iterator pos, int count,elem);         //迭代器指向位置pos插入count个元素elem
 *   erase(const_iterator pos);                          //删除迭代器指向的元素
 *   erase(const_iterator start, const_iterator end);    //删除迭代器从start到end之间的元素
 *   clear();                                            //删除容器中所有元素
 */

void prinfVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    prinfVector(v1);    //10 11 12 13 14

    //删除最后一个元素,直接删除,不返回值
    v1.pop_back();
    prinfVector(v1);    //10 11 12 13

    //插入,第一个参数是迭代器,代表了位置参数
    //在开始位置插入100
    v1.insert(v1.begin(), 100);
    prinfVector(v1);    //100 10 11 12 13

    //在结束位置插入两个1000
    v1.insert(v1.end(), 3, 1000);
    prinfVector(v1);    //100 10 11 12 13 1000 1000 1000

    //删除,参数是迭代器,删除第一个
    v1.erase(v1.begin());
    prinfVector(v1);    //10 11 12 13 1000 1000

    //从删除开始到结束
    v1.erase(v1.begin(), v1.end());
    prinfVector(v1);    //空,全部删除

    //删除全部
    v1.clear();
}

int main() {
    test01();
    return 0;
}
