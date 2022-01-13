#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>


using namespace std;

/**
 * for_each
 * 函数原型：
 * for_each(iterator beg, iterator end, _func);
 *   遍历算法 遍历容器元素
 *   beg 开始迭代器
 *   end 结束迭代器
 *   _func 函数或者函数对象
 */

void print1(int val) {
    cout << val << " ";
}

void test1() {
    vector<int> v{1, 4, 3, 6, 5};

    //使用普通函数
    for_each(v.begin(), v.end(), print1);        //1 4 3 6 5 10 11 12 13 14
    cout << endl;   //1 4 3 6 5
}


/**
 * 常用查找算法
 *  掌握常用的查找算法
 * 算法简介：
 *  find                //查找元素
 *  find_if             //按条件查找元素
 *  adjacent_find       //查找相邻重复元素
 *  binary_search       //二分查找法
 *  count               //统计元素个数
 *  count_if            //按条件统计元素个数
 */

class Greater5{
public:
    bool operator()(int a){
        return a > 5;
    }
};

void test2(){
    vector<int> v{1, 2, 5, 3, 5, 0, 6, 7, 89};
    auto pos = find(v.begin(), v.end(), 0);
    if(pos != v.end()){
        cout << *pos << endl;   //0
    }

    pos = find_if(v.begin(), v.end(), Greater5());
    if(pos != v.end()){
        cout << *pos << endl;   //6
    }
}


/**
 * sort
 * random_shuffle
 */
void test3(){
    vector<int> v{1, 2, 5, 3, 5, 0, 6, 7, 89};
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), print1);       //0 1 2 3 5 5 6 7 89
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), print1);       //89 7 6 5 5 3 2 1 0
    cout << endl;

    //随机打乱
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print1);       //0 7 2 6 89 3 1 5 5
    cout << endl;
}


/**
 * merge
 *  两个容器元素合并，并存储到另一容器中
 * 函数原型：
 *  merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 *
 *  容器元素合并，并存储到另一容器中
 *  注意: 两个容器必须是有序的,顺序必须一致,合并完之后结果是有序的,不然合并完结果是无序的
 *  beg1   容器1开始迭代器
 *  end1   容器1结束迭代器
 *  beg2   容器2开始迭代器
 *  end2   容器2结束迭代器
 *  dest   目标容器开始迭代器
 *
 * reverse
 * 将容器内元素进行反转
 */
void test4(){
    deque<int> d1{1, 3, 4, 5, 9, 10};
    deque<int> d2{0, 1, 2, 5, 6, 8, 9};
    deque<int> d3;
    d3.resize(d1.size()+d2.size());

    merge(d1.begin(), d1.end(),d2.begin(),d2.end(),d3.begin());
    for_each(d3.begin(), d3.end(), print1); //0 1 1 2 3 4 5 5 6 8 9 9 10
    cout << endl;
    reverse(d1.begin(), d1.end());
    for_each(d1.begin(), d1.end(), print1); //10 9 5 4 3 1
    cout << endl;
}

/**
 * copy
 * 功能描述：
 *  容器内指定范围的元素拷贝到另一容器中
 * 函数原型：
 *  copy(iterator beg, iterator end, iterator dest);
 *
 * transform
 * 功能描述：
 *  搬运容器到另一个容器中
 * 函数原型：
 *  transform(iterator beg1, iterator end1, iterator beg2, _func);
 */
void test5(){
    list<int> l1 = {1, 2, 3, 4, 5};
    list<int> l2;
    l2.resize(l1.size());
    copy(l1.begin(), l1.end(), l2.begin());
    for(int &i: l2){
        cout << i << " ";
    }
    //1 2 3 4 5
    cout << endl;

    list<int> l3;
    l3.resize(l1.size());
    //transform(l1.begin(), l1.end(), l3.begin());
}


/**
 * replace
 * 功能描述：
 *  将容器内指定范围的旧元素修改为新元素  所有元素都替换
 * 函数原型：
 *  replace(iterator beg, iterator end, oldvalue, newvalue);
 *
 * replace_if
 * 功能描述:
 *  将区间内满足条件的元素，替换成指定元素
 * 函数原型：
 *  replace_if(iterator beg, iterator end, _pred, newvalue);
 */
void test6(){
    vector<int> v1{1, 2, 2, 4, 5, 6};
    replace(v1.begin(),v1.end()-3, 2, 9);
    for_each(v1.begin(), v1.end(), print1);     //1 9 9 4 5 6
    cout << endl;

    vector<int> v2{1, 2, 3, 7, 6, 6};
    replace_if(v2.begin(), v2.end(), Greater5(), -1);
    for_each(v2.begin(), v2.end(), print1);     //1 2 3 -1 -1 -1
    cout << endl;
}



int main(){
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    cout << endl;
    test4();
    cout << endl;
    test5();
    cout << endl;
    test6();
    cout << endl;
    return 0;
}