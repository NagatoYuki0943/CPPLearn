#include <iostream>

using namespace std;

int main() {
    int i, a;
    /*//for循环也支持break打破循环
    for(i=0;i<10;i++){
        cout << i << endl;

    }*/

    //敲桌子,输出1-100,如果是7的倍数,个位或者十位有7,就输出敲桌子
    for (i = 1; i < 101; i++) {
        if (i % 7 == 0) {              //取7的余数=0,说明是7的倍数
            cout << "敲桌子" << endl;
        } else if (i % 10 == 7) {      //取10的余数=7,说明个位有7
            cout << "敲桌子" << endl;
        } else if (i / 10 == 7) {      //除以10如果等于7,说明十位是7
            cout << "敲桌子" << endl;
        } else {
            cout << i << endl;
        }
    }
    return 0;
}
