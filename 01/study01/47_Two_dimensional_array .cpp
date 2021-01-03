#include <iostream>

using namespace std;

int main() {
    /*
     * 二维数组定义方式
     * 1.数据类型 数组名[行数][列数];
     * 2.数据类型 数组名[行数][列数]={{数据1,数据2},{数据3,数据4}}
     * 3.数据类型 数组名[行数][列数]={数据1,数据2,数据3,数据4}
     * 4.数据类型 数组名[][列数]={数据1,数据2,数据3,数据4}
     */
    int array[2][3];
    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[1][0] = 4;
    array[1][1] = 5;
    array[1][2] = 6;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    int array1[3][2] = {{7,  8},      //这样写更直观
                        {9,  10},
                        {11, 12}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }

    int array2[2][3] = {1, 2, 3,   //里面不用大括号也行
                        4, 5, 6};
    int array3[][3] = {
            1, 2, 3,
            4, 5, 6
    };


    return 0;
}