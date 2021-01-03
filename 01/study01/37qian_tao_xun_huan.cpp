#include <iostream>

using namespace std;

int main() {
    /*int i,j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            cout << "*" ;
            //cout << "*" << endl;会换行
            //cout << "*" ;不会换行
        }
        cout << endl;
        //cout << endl;直接换行
    }*/

    //乘法口诀表
    int a, b;
    for (a = 1; a <= 9; a++) {       //行数
        for (b = 1; b <= a; b++) {   //列数<=行数
            cout << b << "x" << a << "=" << b * a << "\t";
        }
        cout << endl;

    }


    return 0;
}
