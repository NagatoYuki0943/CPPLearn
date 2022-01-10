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
        cout << "��ҳ,������,��¼,ע��...(����ͷ��)" << endl;
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

    //ͬ���������÷���
    java.content();
    java.Basic::content();


    cout << java.a << endl;
    //ͬ���������÷���
    cout << java.b << "\t" << java.Basic::b << endl;

    //ͬ����̬�������÷���
    cout << Java::c << "\t" << Java::Basic::c << endl;

    //ͬ����̬�������÷���
    Java::printC();
    Java::Basic::printC();
    return 0;
}