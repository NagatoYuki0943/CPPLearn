#include "iostream"

using namespace std;

int main() {
    //switch中只能放整形或者字符型,float          switch  case :  break  default
    //switch的执行效率比if高
    //case代码长的话要用{}括起来,下一行示例


    //给电影打分
    //9-10 very好
    //7-8  挺好
    //5-6  还行
    //0-4  烂片
    int a = 0;
    //float a=0; 不能再switch中运行
    cout << "请打分:0-10" << endl;
    cin >> a;
    if (a > 10 || a < 0) {
        cout << "请输入0-10之间的数字,将会退出!!!" << endl;
        exit;      //退出
    }
    //switch中只能放整形或者字符型,float
    switch (a) {
        case 10 :
        case 9  :
            cout << "非常好" << endl;
            break;
        case 8  :
        case 7  :
            cout << "挺好" << endl;
            break;
        case 6  :
        case 5  :
            cout << "还行" << endl;
            break;
            //default 上面的都不行就执行这个
        default :
            cout << "烂片" << endl;
    }

    return 0;
}
