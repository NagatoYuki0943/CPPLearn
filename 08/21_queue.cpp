#include <iostream>
#include <queue>

using namespace std;

/**
 * push pop
 * front back
 *
 * empty
 * size
 */

void test1(){
    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(4);
    q.push(5);
    q.push(9);

    cout << q.size() << endl;   // 5

    while (!empty(q)){
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
    //1 9
    //5 9
    //4 9
    //5 9
    //9 9
}


int main(){
    test1();
    return 0;
}