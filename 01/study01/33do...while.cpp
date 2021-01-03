#include <iostream>

using namespace std;

int main() {
    //do{}while 先执行一次再判断
    /*int a=0;
    do{
        cout << a << endl;        //输出0-9
        a++;
    }while (a<10);
    */
    //求水仙花数,一个三位数,每个位上的数字的三次方等于它本身
    int b = 100, c, d, e;
    do {
        c = b % 10;          //取个位
        d = (b / 10) % 10;     //取十位
        e = b / 100;         //取百位
        if (b == c * c * c + d * d * d + e * e * e) {
            cout << b << endl;
        }
        b++;
    } while (b < 1000);


    return 0;
}
