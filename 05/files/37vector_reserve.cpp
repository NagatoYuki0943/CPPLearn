#include <iostream>
#include <vector>

using namespace std;

/**
 * vector预留空间
 * 功能描述:
 *  减少vector在动态扩展容量时的扩展次数
 * 函数原型:
 *  reserve(int len);   //容器预留len个元素长度,预留位置不初始化,元素不可访问
 *                      resize()会自动填充0,reserve不会
 * 如果数据量较大,可以使用reserve一次性预留空间
 */

void test01() {
    vector<int> v;
    v.reserve(100000);
    int num = 0;    //统计开辟内存的次数
    int *p = NULL;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
        //扩充会更换内存位置,所以可以查看扩充次数
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << num << " times" << endl;    //15 times   不增加reserve要开辟15次
                                        //1 times    增加reserve之后只有一次

}

int main() {
    test01();
    return 0;
}
