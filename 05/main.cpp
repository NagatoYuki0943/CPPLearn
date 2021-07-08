#include <iostream>

using namespace std;

//int a[] = {1, 2, 3, 4};
//
//void func1(int b[]){
//    b[0] = 10;
//}
//
//void func2(int b[]){
//    cout << b[0] << endl;
//}

//int main() {
//    func1(a);
//    func2(a);
//    return 0;
//}

class MyCompare{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};


int main() {
    // 通过对象调用
    MyCompare myCompare;
    bool res = myCompare(2, 1);
    cout << res << endl;    // 1

    // 类名两个括号直接调用
    res = MyCompare()(1, 2);
    cout << res << endl;    // 0
    return 0;
}