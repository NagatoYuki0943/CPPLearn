#include <iostream>
#include "vector"

using namespace std;

class Basic{
public:
    int a;
    int b;
    static int c;
    Basic(int a, int b){
        this->a = a;
        this->b = b;
    }

    void header() {
        cout << "首页,公开课,登录,注册...(公共头部)" << endl;
    }

    void content(){
        cout << "Baaaaaaaaaaaaaaaaaasic" << endl;
    }

    static void printC(){
        cout << Basic::c << endl;
    }
};
int Basic::c = 999;


class Java: public Basic{
public:
    int b;
    static int c;
    Java(int a, int b): Basic(a, b){
        this->b = b;
    }

    void content(){
        cout << "Jaaaaaaaaaaaaaaaaaava" << endl;
    }

    static void printC(){
        cout << Java::c << endl;
    }
};
int Java::c = 1000;


int main(){
    Java java = Java(1, 2);
    java.header();

    //同名函数调用方法
    java.content();
    java.Basic::content();


    cout << java.a << endl;
    //同名变量调用方法
    cout << java.b << "\t" << java.Basic::b << endl;

    //同名静态变量调用方法
    cout << Java::c << "\t" << Java::Basic::c << endl;

    //同名静态方法调用方法
    Java::printC();
    Java::Basic::printC();
    return 0;
}