#include <iostream>

using namespace std;
/**
 * const修饰结构体
 */
struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
};

//值传递传递的数据量太大,内存开销大,更推荐使用指针传递,不过指针传递容易影响元数据,所以使用const常量指针
void printStudent(const struct Student *s) {
    //s->age=100; //会影响元数据,加上const之后不能更改
    cout << "printStudent\t姓名:" << s->name << " 年龄:" << s->age << " 分数:" << s->score << endl;
}

int main() {
    struct Student s = {"小明", 20, 70};
    printStudent(&s);
    cout << "main\t\t\t姓名:" << s.name << " 年龄:" << s.age << " 分数:" << s.score << endl;
    return 0;
}