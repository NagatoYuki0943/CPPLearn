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
    vector<int> v1;
    //预留空间
    v1.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    //赋值长度
    vector<int> v2(v1.begin(), v1.end()-1);
    printVector(v2);    //0 1 2 3 4 5 6 7 8

    //assign赋值
    vector<int> v2_1;
    v2_1.assign(v1.begin(), v1.end());
    printVector(v2_1);    //0 1 2 3 4 5 6 7 8 9

    //10个9
    vector<int> v3(10,9);
    printVector(v3);    //5 5 5 5 5

    vector<int> v3_1;
    v3_1.assign(5, 5);
    printVector(v3_1);    //9 9 9 9 9 9 9 9 9 9

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);
    //直接使用等号也可以
    vector<int> v4_1 = v4;
    printVector(v4_1);  //9 9 9 9 9 9 9 9 9 9

    //{}初始化
    vector<int> v5 = {1, 3, 4, 6};
    v5.reserve(10);
    printVector(v5);

    vector<int> v5_1;
    v5_1 = {1, 3, 4, 5, 9};
    printVector(v5_1);  //1 3 4 5 9
    cout << "--------------------------" << endl;

    cout << v5.empty() << endl;     //0 是否为空
    cout << v5.size() << endl;      //4 长度
    cout << v5.capacity() << endl;  //10 容量

    v5.resize(10, 0);   //重新改长度,多余位置默认为0
    printVector(v5);             //1 3 4 6 0 0 0 0 0 0
}

void test2(){
    //{}初始化
    vector<int> v5 = {1, 3, 4, 6};
    v5.reserve(10);
    printVector(v5);

    cout << v5.empty() << endl;     //0 是否为空
    cout << v5.size() << endl;      //4 长度
    cout << v5.capacity() << endl;  //10 容量

    v5.resize(10, 0);   //重新改长度,多余位置默认为0
    printVector(v5);             //1 3 4 6 0 0 0 0 0 0
}

void test3(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    printVector(v1);    //10 11 12 13 14

    //删除最后一个元素,直接删除,不返回值
    v1.pop_back();

    //插入
    v1.insert(v1.begin()+1, 99);

    //front第一个值, back最后一个
    cout << v1.front() << " " << v1.back() << endl; //10 13

    // at和[]相同
    cout << v1[0] << v1.at(0) << endl;  //10
    v1[0] = -10;
    v1.back() = 233;    //重新赋值

    //删除指定位置
    v1.erase(v1.end()-1);
    printVector(v1);    //-10 99 11 12

    //清除全部
    v1.clear();
}


int main(){
    //test1();
    //test2();
    test3();
    return 0;
}