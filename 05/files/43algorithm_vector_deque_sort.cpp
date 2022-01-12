#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * vector和deque排序
 *  利用算法对vector和deque进行排序
 * 算法:
 *  sort(iterator beg, iterator end)`   //对beg和end区间内元素进行排序
 *                                      //beg和end可以替换为其他iterator
 *                                      //默认升序
 */
void test01() {
    deque<int> d1{5, 13, 2, 45, 12, 4, 6, 9};
    //排序
    sort(d1.begin(), d1.end());
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1[i] << " ";   //2 4 5 6 9 12 13 45
    }
    cout << endl;

    deque<int> d2{5, 13, 2, 45, 12, 4, 6, 9};
    //排序
    sort(d2.begin() + 1, d2.end());
    for (int i = 0; i < d2.size(); ++i) {
        cout << d2[i] << " ";   //5 2 4 6 9 12 13 45
    }
    cout << "----------------------" <<endl;
}

void test02(){
    vector<int> v1{5, 13, 2, 45, 12, 4, 6, 9};
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << " ";   //2 4 5 6 9 12 13 45
    }
}

int main() {
    test01();
    test02();
    return 0;
}
