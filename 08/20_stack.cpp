#include <iostream>
#include <stack>

using namespace std;

/**
 * stack栈
 *
 * push pop top
 * empty size
 */

void test1(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.size() << endl;   //4

    //s.empty()也能判断
    while (!empty(s)){
        cout << s.top() << " ";
        s.pop();
    }
    //4 3 2 1
}



int main(){
    test1();
    return 0;
}