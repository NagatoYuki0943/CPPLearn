#include <iostream>
#include <vector>

using namespace std;
/**
 * vector数据结构和数组非常类似,也成为单端数组
 * vector和普通数组区别:
 *  不同之处在于数组是静态空间,vector是动态扩展
 *
 * 动态扩展:并不是在原空间之后续接新空间,而是找更大的内存空间,然后将原数据拷贝到新空间,释放原空间
 *
 * vector容器的迭代器是支持随机访问的迭代器
 *
 * vector构造函数
 * 创建vector容器
 * 函数原型：
 *  vector<T> v;                		 //采用模板实现类实现，默认构造函数
 *  vector(v.begin(), v.end());          //将v.begin(), v.end())区间中的元素拷贝给本身。
 *  vector(n, elem);                     //构造函数将n个elem拷贝给本身。
 *  vector(const vector &vec);           //拷贝构造函数。
 *  vector<?> name = {值1,值2,值3}
 *
 *  begin()和end()返回iterator迭代器
 *
 *  front()和back()代表第一个和最后一个数据
 *  push_back()和pop_back()对尾部数据进行操作
 */

//打印vector
void printVector(vector<int> &v) {
    //begin()是第一个,end()是最后一个的下一个
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    //默认构造
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);    //0 1 2 3 4 5 6 7 8 9

    //通过区间方式添加
    //begin()是第一个,end()是最后一个的下一个
    vector<int> v2(v1.begin() + 1, v1.end() - 1);
    printVector(v2);    //1 2 3 4 5 6 7 8

    //n个elem构造
    vector<int> v3(10, 100);
    printVector(v3);    //100 100 100 100 100 100 100 100 100 100

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);    //100 100 100 100 100 100 100 100 100 100

    //初始化
    vector<int> v5{1, 2, 3, 4, 5, 6};
    printVector(v5);    //1 2 3 4 5 6
}

int main() {
    test01();
    return 0;
}
