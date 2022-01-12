#include <iostream>
#include <deque>

using namespace std;
/**
 * deque是双端队列
 * push_back push_front pop_back pop_front
 * 没有capacity和reserve
 *
 * assign insert erase clear push_back pop_back push_front pop_front
 * begin end
 * front back at []
 * empty size
 */

void printDeque(deque<int> &d){
    for(auto &i: d){
        cout << i << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1 = {1, 3, 5};
    d1.push_back(4);
    d1.push_front(0);
    printDeque(d1);     //0 1 3 5 4

    cout << d1.front() << " " << d1.back() << endl; // 0 4
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);     //1 3 5

    deque<int> d2 = d1;

    deque<int> d3(d1);

    deque<int> d4(d1.begin(), d1.end()-1);

    deque<int> d5;
    d5.assign(d1.begin(), d1.end()-2);

    deque<int> d6(5, 10);
    deque<int> d7;
    d7.assign(8,10);
}


void test2(){
    deque<int> d1 = {1, 2};
    cout << d1.empty() << endl;     //0

    //新大小,默认值
    d1.resize(10, 0);
    cout << d1.size() << endl;      //10
}

void test3(){
    deque<int> d1 = {1, 2};
    //插入
    d1.insert(d1.end()-1,5);
    printDeque(d1);               //1 5 2

    //删除
    d1.erase(d1.begin());   //5 2
    printDeque(d1);

    cout << d1[0] << d1.at(0) << endl;

    d1.clear();
}


int main(){
    //test1();
    //test2();
    test3();
    return 0;
}