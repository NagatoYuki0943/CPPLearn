#include <iostream>
#include <vector>

using namespace std;

/**
 * vector互换容器
 *  实现两个容器内元素互换
 * 函数原型:
 *  swap(vector); //将vector与本身的元素互换
 *  数据量不同也可以互换
 */

template<typename T>
void printVector(vector<T> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test01() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    printVector<int>(v1);   //1 2 3 4 5
    printVector<int>(v2);   //9 8 7 6 5 4 3 2 1 0
    //互换位置
    v1.swap(v2);
    printVector<int>(v1);   //9 8 7 6 5 4 3 2 1 0
    printVector<int>(v2);   //1 2 3 4 5

}

//实际用途
//巧用swap可以收缩内存空间
void test02() {
    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
    }
    //capacity比size大
    cout << "v's capacity is " << v.capacity() << endl;     //v's capacity is 131072
    cout << "v's size is " << v.size() << endl;             //v's size is 100000

    //重新指定大小
    v.resize(3);
    cout << "v's capacity is " << v.capacity() << endl;     //v's capacity is 131072
    cout << "v's size is " << v.size() << endl;             //v's size is 3
    //大小为3,容量还是131072,浪费空间

    //使用swap收缩内存
    vector<int> (v).swap(v);
    //vector<int> (v) 是匿名对象,它没有名字,(v)是按照v进行初始化对象,容量和大小都是3,
    //再和v交换内容,交换完之后匿名对象的资源会被回收,v就保存了新的匿名函数的数据


    cout << "v's capacity is " << v.capacity() << endl;     //v's capacity is 3
    cout << "v's size is " << v.size() << endl;             //v's size is 3
}

int main() {
    test01();
    test02();
    return 0;
}
