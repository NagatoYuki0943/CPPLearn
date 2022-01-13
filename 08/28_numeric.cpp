#include <iostream>
#include <deque>
#include <list>
#include <numeric>

using namespace std;

void printList(list<int> &l){
    for(int &i: l){
        cout << i << " ";
    }
    cout << endl;
}


/**
 *  accumulate(iterator beg, iterator end, value);
 *  计算容器元素累计总和
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 起始值累加值,一般为0
 *
 *  fill(iterator beg, iterator end, value);
 *  向容器中填充元素
 *  beg 开始迭代器
 *  end 结束迭代器
 *  value 填充的值
 */
void test1(){
    list<int> l1;
    for (int i = 1; i < 101; ++i) {
        l1.push_back(i);
    }

    int sum = accumulate(l1.begin(), l1.end(),0);
    cout << sum << endl;    //5050

    list<int> l2{1, 2, 3, 4, 5};
    //先加减才行
    fill(++l2.begin(), --l2.end(), 9);
    printList(l2);  //1 9 9 9 5

}








int main(){
    test1();
    cout << endl;
    return 0;
}