#include <iostream>
#include <vector>
#include <algorithm>    //标准算法头文件

using namespace std;

/**
 * vector可以理解为数组,
 * 容器: vector
 * 算法: for_each
 * 迭代器: vector<int>::iterator
 */

//回调函数
void myPrint(int val) {
    cout << val << " ";
}

void test01() {
    //创建vector容器
    vector<int> v;

    //插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器访问数据中的数据
    vector<int>::iterator itBegin = v.begin();  //起始迭代器,指向容器中的第一个元素
    auto itEnd = v.end();  //容器中最后一个元素的下一个位置

    //第一种遍历,把迭代器当做指针
    while (itBegin != itEnd) {
        cout << *itBegin << " ";   //10 20 30 40
        itBegin++;
    }
    cout << endl;
    cout << "--------------------" << endl;

    //第二种遍历方式
    for (auto it = v.begin(); it != v.end(); it++) {
        //*it是上面的<>中的数据类型
        cout << *it << " ";     //10 20 30 40
    }
    cout << endl;
    cout << "--------------------" << endl;

    //第三种遍历 利用STL中提供的遍历算法
    //参数是开始,结束,回调函数
    for_each(v.begin(), v.end(), myPrint);    //10 20 30 40
    cout << endl;
    cout << "--------------------" << endl;
}


int main() {
    test01();
    return 0;
}
