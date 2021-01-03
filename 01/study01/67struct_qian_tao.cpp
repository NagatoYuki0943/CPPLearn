#include <iostream>
#include <string>

using namespace std;
//一个结构体嵌套使用另一个结构体,一对一,一对多的话可以使用数组
struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
};

struct Teacher {           //一个老师和一个学生配对,一对一
    int id;
    string name;
    int age;
    struct Student Stu;   //老师的结构体嵌套使用学生的结构体
};

int main() {
    //创建老师
    Teacher t;
    t.id = 10;
    t.name = "老张";
    t.age = 50;
    t.Stu.name = "小王";     //定义学生使用多个点
    t.Stu.age = 20;
    t.Stu.score = 70;

    cout << "老师id:" << t.id << " 老师姓名:" << t.name << " 老师年龄:" << t.age
         << " 老师辅导的学生姓名:" << t.Stu.name << " 学生年龄:" << t.Stu.age << " 学生分数:" << t.Stu.score << endl;
    return 0;
}