#include <iostream>

using namespace std;


class Animal{
public:
    //虚函数,实现多态
    virtual void speak(){
        cout << "Animal" << endl;
    }
};

class Dog: public Animal{
public:
    //override可以加,可以不加
    void speak() override{
        cout << "Dog" << endl;
    }
};


class Cat: public Animal{
public:
    void speak() override{
        cout << "Cat" << endl;
    }
};

//只有父类是虚函数,这里的调用才是传入的类的方法
void speak(Animal &animal){
    animal.speak();
}


int main(){
    Animal a;
    Dog d;
    Cat c;
    speak(a);   // Animal
    speak(d);   // Dog
    speak(c);   // Cat

    //任何父类指针都能指向子类
    Animal *p = new Dog();
    speak(*p);

    return 0;
}