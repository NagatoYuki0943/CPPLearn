#include <iostream>

using namespace std;

int main() {
    //单行if
    int score = 0;
    cout << "请输出分数" << endl;
    cin >> score;
    //if后面不要加分号,不然后面的全部会执行
    //if (score>600 ) cout << "score>600" << endl ;       /单行可以不用{}
    if (score > 600) {
        if (score > 650) {
            cout << "score >650" << endl;
        } else cout << "score <=650" << endl;
    } else if (score > 500) {
        cout << "score>500" << endl;
    } else if (score > 400) {
        cout << "score>400" << endl;
    } else {
        cout << "score<=400" << endl;
    }
    return 0;


}
