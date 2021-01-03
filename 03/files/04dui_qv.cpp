#include <iostream>

using namespace std;
/**
 * 堆区:由程序员分配释放,如果程序员不释放,程序结束时有操作系统回收
 * 使用 new 在堆区开辟内存           new返回的是该类型的指针,用指针存放
 * 使用delete 删除指针就删除堆区的数据
 * 删除普通变量:delete p;  删除数组:delete[] arr;
 */
/**
 * 在栈区创建二维数组
 * Worker **是指向Worker*的指针,用两个**指向
 * Worker ** newSpace=new Worker* [newSize];
 */
int *func() {
    //利用new关键字可以将数据开辟到堆区
    //new返回的是该类型的指针,用指针存放
    //指针本质也是局部变量,存放在栈上,指针保存的数据是放在堆区
    int *p = new int(10); //int(10) int类型,数值为10
    return p;
}

void test01() {
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据由程序员管理释放
    //释放使用delete p 释放地址
    delete p;
    cout << *p << endl;   //7493760,随机数,因为delete已经释放了p
}

void test02() {
    int *arr = new int[10];//创建长度为10的数组
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 100;     //和普通的数组存放数据一样
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //释放数组,
    delete[] arr;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    /*int *p=func();
    cout << (long long)p << endl; //堆区地址
    cout << *p << endl;
    cout << *p << endl;   //输出多次也可以,不会像栈区一样被销毁
    cout << *p << endl;*/

    //test01();
    test02();


    system("pause");
    return 0;
}
