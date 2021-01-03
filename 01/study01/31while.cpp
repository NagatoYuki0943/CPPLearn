#include <iostream>
#include "ctime"    //包含ctime

using namespace std;

int main() {
    //break可以是while退出循环

    /*int a=0,b=0;
    cin >> a;
    while (a<10){
        a++;
        b++;
    }
    cout << "a=" << a << endl;
    cout << "运行了b=" << b << "次" <<endl;

    int num=0;
    while (num<10){
        cout << num << endl;
        num++;
    }*/

    //猜数字
    //1.系统生成随机数 rand
    //2.玩家进行猜测
    //3.猜对了,退出
    //4.猜错,提示猜的过大或过小
    int a, b = 0;
    srand((unsigned int) time(NULL));
    a = rand() % 100 + 1;       //rand()%100生成0-99的随机数 ,默认每次都是随机数,要想每次不一样要加入种子,添加系统时间,上面那一行就是


    while (1) {

        cin >> b;
        if (b > a) {
            cout << "猜测过大" << endl;
        } else if (b < a) {
            cout << "猜测过小" << endl;
        } else {
            cout << "猜对了,结果是" << a << endl;
            break;
        }

    }


    return 0;

}
