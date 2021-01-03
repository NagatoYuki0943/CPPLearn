#include <iostream>

using namespace std;

int main() {
    //数组名是常量,不能重新赋值
    //数组所有数据都是相通的数据类型,数组是由连续的内存位置组成的
    //arr[10] 10个;  arr[]= 自动判断个数;
    //arr[i]=arr[i+1],无论数组里面是什么东西,可以直接赋值,不用分开赋值单个数据里面的内容
    int arr1[5];      //这样定义必须定义长度
    arr1[0] = 989;      //可以这样赋值

    cout << arr1[0] << endl;


    int arr2[10] = {1, 2, 3, 4, 5,};
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << endl;   //数组从0开始计数    初始化时没有全部给值,后面的默认为0
    }
    int arr3[] = {4, 58, 6, 4, 24, 5};    //可以自动获取长度
    cout << arr3 << endl;      //这样不会输出全部,输出数组在内存中的首地址
    return 0;
}
/**
 * c++和C#的不同之处
 * C/C++数组声明:  类型 数组名[]={};              int arr[]={};
 *  
 * 指针分为  常量的指针:const int * p     指针是常量:int * const p;   双:const int * const p;
 * C++中new是在堆区创建数据, int * p = new int(10);  删除使用delete 
 * 在堆区中创建数组   int * p = new int[10];         删除使用delete[] 
 * 
 * C#数组声明: 类型[] 数组名 = new 类型名[]{}     int[] ints=new int[6]{1,2,3,4,5,6};
 * 
 *  在C++11中 初始化可以省略 "="  
 *	int i[5] {1, 5, 2, 3, 6}
 *  float f[] {1.5, 25, 0.552, 2.55}    
 */