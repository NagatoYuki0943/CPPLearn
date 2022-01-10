#include <iostream>
#include <vector>
using namespace std;

class Student{
    //友元函数
    friend void goodFriend(Student &student);
    //友元类
    friend class Friend;

public:
    string name;
    int age;

    Student(string name, int age) {
        this->name = name;
        this->age = age;
        Student::sum += 1;
        this->hobby.emplace_back("pantyhose");  //和push_back同理
        this->hobby.emplace_back("stocking");
    }

    //拷贝构造
    Student(const Student &student){
        this->name = student.name;
        this->age = student.age;
        Student::sum += 1;
    }

    static int sum;         //静态变量要类内声明,类外初始化
    static void getSum(){   //静态函数可以再里面实现
        cout << Student::sum << endl;
    }

private:
    vector<string> hobby;
};

int Student::sum = 0;   //静态变量要类内声明,类外初始化


//友元函数
void goodFriend(Student &student) {
    for (auto &i: student.hobby) {
        cout << i << endl;
    }
}

//友元类
class Friend{
public:
    Student *student;

    Friend(){
        this->student = new Student("C", 18);
    }
    void visit(){
        for (auto &i: student->hobby) {
            cout << i << endl;
        }
    }
};

int main(){
    Student student1("A", 15);
    cout << student1.name << "\t" << student1.age << endl;
    Student student2 = Student("B", 16);
    cout << student2.name << "\t" << student2.age << endl;
    Student student3 = Student(student2);
    cout << student3.name << "\t" << student3.age << endl;
    Student::getSum();

    cout << "---------" << endl;
    goodFriend(student1);
    cout << "---------" << endl;

    Friend f;
    f.visit();


    return 0;
}