#include <iostream>
using namespace std;
/**
 * C++中全局变量可以直接被函数修改,不用global
 * 变量直接传递给函数没有改变,要使用指针或引用,对比数组直接改变值了,因为传递的就是指针
 *
 * python中全局变量可以再函数中直接使用,不过对比不可变类型(bool,int,float,string,tuple),不能被修改,除非用global引入
 *     对于可变类型(list,set,dict),可以修改里面的值,但是不能直接 = 赋值,除非使用global
 * 函数参数没法修改不可变类型的值,只能修改可变类型里面的值,python本身就是引用传值,所以没有其他引用了
 *
 * php中全局变量和数组只有在函数中使用global引入才能被查看和修改,
 * 函数参数要使用引用传递才能修改变量和数组中的值
 */


int num1 = 10;
int arr1[] = {1, 2, 3};
/**
 * C++中全局变量可以直接被函数修改,不用global
 */
void func1(){
    num1++;
    arr1[0] = 111;
}

void func2(){
    cout << num1 << endl;       //  11
    cout << arr1[0] << endl;    //  111
}

void func3(int a, int b[]){
    a++;
    b[0] = 999;
}


int main(){
    func1();
    func2();

    /**
     * 变量直接传递给函数没有改变,要使用指针或引用,对比数组直接改变值了,因为传递的就是指针
     */
    int num2 = 0;
    int arr2[] = {9, 10};
    func3(num2, arr2);
    cout << num2 << endl;       //  0
    cout << arr2[0] << endl;    //  999
    return 0;
}