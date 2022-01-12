#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


void printVector(vector<int> &t){
    for(auto &i: t){
        cout << i << " ";
    }
    cout << endl;
}

void printDeque(deque<int> &d){
    for(auto &i: d){
        cout << i << " ";
    }
    cout << endl;
}


void test01(){
    vector<int> a{1, 4, 5, 76, 3};
    a.insert(a.begin(), 0);
    a[1] = 999;
    a.push_back(-55);
    sort(a.begin(), a.end());
    printVector(a);                     //-55 0 3 4 5 76 999
    a.erase(a.begin());

    deque<int> b{1, 4, 5, 76, 3};
    b.insert(b.begin(), 0);
    b[1] = 999;
    b.push_back(-55);
    b.push_front(56);
    sort(b.begin(), b.end());
    printDeque(b);                     //-55 0 3 4 5 56 76 999
    b.erase(b.end());
}



int main(){
    test01();
    return 0;
}
