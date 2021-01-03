#include <iostream>

using namespace std;

int main() {
    //break跳出switch,循环或者嵌套循环跳出最近的循环

    //switch
    /*
     cout << "请从1,2,3选择难度" << endl;
     cout << "1=简单" << endl;
     cout << "2=普通" << endl;
     cout << "3=困难" << endl;

     int select = 0; //创建结果变量
     cin >> select;
     if(select!=1 && select!=2 && select!=3){
         cout << "请从1,2,3选择难度" << endl;
         exit;
     }
     switch (select) {
         case 1 :
             cout << "您选择的是简单难度" << endl;
             break;
         case 2 :
             cout << "您选择的是普通难度" << endl;
             break;
         case 3 :
             cout << "您选择的是困难难度" << endl;
     }*/

    //for循环
    /*int i;
    for(i=0;i<10;i++){
        if(i==5){
            break;
        }
        cout << i;

    }*/

    //嵌套循环
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 5) {   //每行打印5个
                break; //跳出循环
            }
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
