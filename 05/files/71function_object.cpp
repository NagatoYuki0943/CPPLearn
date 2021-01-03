#include <iostream>
#include <string>

using namespace std;

/**
 * STL- 函数对象
 * 函数对象概念
 *  重载函数调用操作符()的类，其对象常称为函数对象
 *  函数对象使用重载的()时，行为类似函数调用，也叫仿函数
 * 本质：
 *  函数对象(仿函数)是一个类，不是一个函数
 *
 * 函数对象使用
 * 特点：
 *  1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
 *  2.函数对象超出普通函数的概念，函数对象可以有自己的状态
 *  3,函数对象可以作为参数传递
 */

//1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd {
public:
    //重载 ()
    int operator()(int v1, int v2) {
        return v1 + v2;
    }
};

void test01() {
    MyAdd myAdd;
    //1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
    int res = myAdd(1, 2);
    cout << res << endl;        //3
}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
    MyPrint() {
        this->count = 0;
    }

    //重载 ()
    void operator()(string test) {
        cout << test << endl;
        //每次调用自加
        this->count++;
    }

    //内部自己的状态
    int count;
};

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02() {
    MyPrint myPrint;
    myPrint("FXXK");    //FXXK
    myPrint("FXXK");    //FXXK
    myPrint("FXXK");    //FXXK
    myPrint("FXXK");    //FXXK
    cout << "MyPrint's count is " << myPrint.count << endl;     //MyPrint's count is 4
}


//3,函数对象可以作为参数传递  MyPrint &myPrint 是参数
void doPrint(MyPrint &myPrint, string test) {
    myPrint(test);
}

//3,函数对象可以作为参数传递
void test03() {
    MyPrint myPrint;
    //当做参数
    doPrint(myPrint, "test03"); //test03
}

int main() {
    test01();
    cout << "--------------------" << endl;
    test02();
    cout << "--------------------" << endl;
    test03();


    return 0;
}
