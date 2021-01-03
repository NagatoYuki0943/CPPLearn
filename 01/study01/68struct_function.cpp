#include <iostream>

using namespace std;
/**
 * 结构体作在函数参数中传递
 * 值传递:    不会改变实际参数
 * 地址传递:  会改变实际参数
 */
struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
};

//值传递
void printStudent1(Student s) {
    s.age = 100;  //不会影响原数据
    cout << "printStudent1\t姓名:" << s.name << " 年龄:" << s.age << " 分数:" << s.score << endl;
}

//地址传递
void printStudent2(Student *s) {
    s->age = 100; //会影响原数据
    cout << "printStudent2\t姓名:" << s->name << " 年龄:" << s->age << " 分数:" << s->score << endl;
}

int main() {
    struct Student s = {"小明", 20, 70};

    cout << "在main函数中打印\t姓名:" << s.name << " 年龄:" << s.age << " 分数:" << s.score << endl;
    //printStudent1(s);   //参数为结构体
    printStudent2(&s);  //参数为结构体地址,使用 &
    cout << "在main函数中打印\t姓名:" << s.name << " 年龄:" << s.age << " 分数:" << s.score << endl;
    return 0;
}