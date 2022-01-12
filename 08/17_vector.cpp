#include <iostream>
#include <vector>

using namespace std;

//打印vector
template<typename T>
void printVector(vector<T> &t){
    for(auto &i: t){
        cout << i << " ";
    }
    cout << endl;
}

void test1(){
    vector<int> v1 = {1, 2, 4, 5, 76};
    vector<int> v2 = {0, 5, 8, 13, 6};
    //交换
    v1.swap(v2);
    printVector(v1);    //0 5 8 13 6
    printVector(v2);    //1 2 4 5 76

    //通过交换收缩内存空间
    //vector<int> (v1).swap(v1);
    v1.shrink_to_fit(); //新写法
}


int main(){
    test1();
    return 0;
}