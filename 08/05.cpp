#include <iostream>

using namespace std;

class Base{
public:
    void speak(){
        cout << "Base speak" << endl;
    }
    virtual void answer(){
        cout << "Base answer" << endl;
    }

    //这个方法默认只会调用父类方法,除非父类的方法使用了virtual
    void use(){
        this->speak();
        this->answer();
    }
};

class Son: public Base{
    void speak(){
        cout << "Son speak" << endl;
    }
    void answer(){
        cout << "Son answer" << endl;
    }
};




int main(){
    Son son = Son();
    son.use();
    //Base speak    这个方法没有virtual,永远调用父类方法
    //Son answer    这个方法有virtual,会调用子类方法
}