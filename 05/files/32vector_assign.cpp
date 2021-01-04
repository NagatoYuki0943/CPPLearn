#include <iostream>
#include <vector>

using namespace std;
/**
 * vector赋值操作
 * 功能描述：
 * 给vector容器进行赋值
 * 函数原型:
 *  vector& operator=(const vector &vec);   //重载等号操作符
 *  直接用 = {值1,值2,值3,...} 也可以
 *  assign(iterator beg, iterator end);     //将[beg, end)区间中的数据拷贝赋值给本身。
 *  assign(n, elem);                        //将n个elem拷贝赋值给本身。
 */

//打印vector
void printVector(vector<int> &v) {
    //begin()是第一个,end()是最后一个的下一个
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void assign() {
    vector<int> v1{1, 2, 3, 4, 5};

    //直接用 = {值1,值2,值3,...} 也可以
    vector<int> v6;
    v6 = {1, 2, 3, 4, 5, 6};
    printVector(v6);    //1 2 3 4 5 6

    vector<int> v2(v1);
    //拷贝构造
    printVector(v2);    //1 2 3 4 5

    // = 赋值
    vector<int> v3 = v1;
    printVector(v3);    //1 2 3 4 5

    vector<int> v4;
    //begin()是第一个,end()是最后一个的下一个

    //v4.assign(v1);    //直接将vector放入assign中会报错

    v4.assign(v1.begin(), v1.end());
    printVector(v4);    //1 2 3 4 5


    vector<int> v5;
    v5.assign(10, 100);
    printVector(v5);    //100 100 100 100 100 100 100 100 100 100


}

int main() {
    assign();
    return 0;
}
