#include <iostream>

using namespace std;
//使用 -> 结构体指针访问结构体属性

struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
};

int main() {
    struct Student s = {"小红", 16, 100};
    //通过指针指向结构体变量
    //int *p=&stu; 这样会报错,类型不对
    //要使用这个"struct Student"类型的指针,struct可以省略
    struct Student *p = &s;
    cout << s.name << endl;       //直接使用 .
    cout << p->name << endl;      //指针使用 ->
    cout << (*p).name << endl;    //也能这样写
    return 0;
}
