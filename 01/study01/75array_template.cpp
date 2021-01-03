#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    /**
     * vector类功能比数组强大,但是付出的代价是效率稍低,如果需要的是长度固定的数组,使用数组是更加的选择,
     * 但是代价是不那么方便和安全.有鉴于此,C++11增加了模板类array,他也位于命名空间std中.与数组一样,
     * array对象的长度也是固定的,也是用栈(静态内存分配),而不是堆区因此效率和数组相同但更方便,更安全.
     * 使用前要包含array头文件
     * array<类型,长度> array名字;   长度只能是常量
     * C++11之后,可将列表  用于vector和array对象,但在C++98中,不能对vector对象这样做
     */

    vector<double> a2{4};  //初始化,不需要(),=可以省略
    array<double, 5> d1{1, 2, 3, 4.5, 5};   //初始化
    cout << d1[1] << endl; //输出第二2

    int m = 5;
    //array<double,m> d2;  //报错,长度不能是变量

    system("pause");
    return 0;
}