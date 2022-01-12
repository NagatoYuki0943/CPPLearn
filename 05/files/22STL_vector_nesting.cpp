#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * vector嵌套
 */

void test01() {
    //一个大容器,里面存放vector<int>
    vector<vector<int>> v;
    //四个小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //向小容器中添加数据
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    //将小容器插入到大的容器中,必须写在填入数字后面,不然插入不了数字
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //通过大容器,遍历数据
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it) {
        //*it是vector<int>
        // (*it).begin()  和 it->begin() 相同
        for (vector<int>::iterator vit = it->begin(); vit != it->end(); ++vit) {
            //*vit 是数字
            cout << *vit << " ";
        }
        cout << endl;
        //1 2 3 4
        //2 3 4 5
        //3 4 5 6
        //4 5 6 7
    }
}

int main() {
    test01();
    return 0;
}
