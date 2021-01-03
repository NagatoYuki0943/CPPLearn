#include <iostream>
#include "string.h"

using namespace std;

int main() {
    //数组名可以查看数组所占内存空间,获取二维数组首地址
    int array1[3][2] = {{7,  8},      //这样写更直观
                        {9,  10},
                        {11, 12}};
    cout << sizeof(array1) << endl;      //24/4=6
    cout << sizeof(array1[0]) << endl;   //8  输出第0行所占的内存
    cout << sizeof(array1[0][0]) << endl;   //4  输出第一个数据所占的内存

    cout << array1 << endl;              //首地址
    cout << &array1[0][0] << endl;       //&取地址 第一个数据的地址
    cout << &array1[0][1] << endl;       //&取地址 第二个数据的地址
    cout << &array1[1] << endl;          //&取地址 第1行数据的地址
    cout << &array1[1][0] << endl;       //&取地址 第二行第1个数据的地址

    cout << endl;
    cout << endl;


    int arr[3][3] = {
            {100, 100, 100},
            {90,  50,  100},
            {60,  70,  80}
    };

    string names[3] = {"张三", "李四", "王五"};

    for (int i = 0; i < 3; i++) {
        int score = 0;   //每个人都要清零
        for (int j = 0; j < 3; j++) {
            score += arr[i][j];
        }
        cout << names[i] << "的总分为:" << score << endl;
    }

    return 0;
}