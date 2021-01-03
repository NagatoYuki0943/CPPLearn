#include <iostream>

using namespace std;
//结构体可以使用数组批量赋值,方式和数组相同

struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
};

int main() {
    //结构体数组
    struct Student stuArray[3] = {
            {"张三", 5, 60},
            {"李四", 6, 80},
            {"王五", 7, 65}
    };
    //重新赋值
    stuArray[2].name = "赵六";
    stuArray[2].age = 50;
    stuArray[2].score = 60;
    for (int i = 0; i < 3; i++) {
        cout << "姓名:" << stuArray[i].name << "\t年龄:" << stuArray[i].age << "\t分数:" << stuArray[i].score << endl;
    }

    return 0;
}