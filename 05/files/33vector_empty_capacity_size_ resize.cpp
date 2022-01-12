#include <iostream>
#include <vector>

using namespace std;

/**
 * 功能描述：
 *  对vector容器的容量和大小操作
 *  函数原型：
 *      empty();                    //判断容器是否为空, 返回bool,0 不为空/ 1为空
 *      capacity();                 //容器的容量
 *      size();                     //返回容器中元素的个数
 *          容量大于等于尺寸
 *      resize(int num);            //重新指定容器的长度为num，若容器变长，则以默认值0填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
 *      resize(int num, elem);      //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。 如果容器变短，则末尾超出容器长度的元素被删除
 */

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test01() {
    vector<int> v1;
    bool res = v1.empty();
    cout << res << endl;    //1
    vector<int> v2{1, 2, 3, 4};
    res = v2.empty();
    cout << res << endl;    //0
    printVector(v2);     //1 2 3 4

    //查看容量
    cout << "v2 capacity : " << v2.capacity() << endl;  //v2 capacity : 4 容量大于等于尺寸
    //查看目前大小
    cout << "v2 size : " << v2.size() << endl;          //v2 size : 4

    //重新设置大小
    v2.resize(10);         //新扩充的默认用 0 补足
    printVector(v2);            //1 2 3 4 0 0 0 0 0 0
    v2.resize(15, 3);    //设置用 3 填充
    printVector(v2);            //1 2 3 4 0 0 0 0 0 0 3 3 3 3 3
}


int main() {
    test01();
    return 0;
}
