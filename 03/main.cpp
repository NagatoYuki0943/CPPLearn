#include <iostream>

using namespace std;


class Person{
public:
    Person(string name, int age, string sex):name(name), age(age), sex(sex){

    }

    void printInfo(){
        cout << this->name << endl;
        cout << this->age << endl;
        cout << this->sex << endl;
    }


private:
    string name;
    int age;
    string sex;
};




int main() {
    Person p1("Ð¡Ã÷1", 15, "ÄÐ");
    p1.printInfo();
    return 0;
}
