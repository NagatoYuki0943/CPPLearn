#include <iostream>

using namespace std;

template<class T1, class T2>
class Base{
public:
    Base(T1 t1, T2 t2);

private:
    T1 name;
    T2 age;
};

//类内函数类外实现
template<class T1, class T2>
Base<T1, T2>::Base(T1 t1, T2 t2) {
    this->name = t1;
    this->age = t2;
}




int main(){
    return 0;
}