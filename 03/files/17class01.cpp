#include <iostream>
#include <string>

using namespace std;
/**
 * C++类中的属性和行为 统称为成员
 * 属性:成员属性 成员变量
 * 行为:成员函数 成员方法
 * C#中有属性,方法和事件
 * PHP中有属性,方法和常量(常量只能由类访问)
 */

//设计一个学生类,属性有姓名和学号,可以给姓名和学号赋值,可以显示学生的姓名和学号
class student {
public://公共权限
    int s_id;
    string s_name;

    //给id姓名赋值
    void setid_name(int id, string name) {
        s_id = id;
        s_name = name;
    }

    //输出
    void showStudent() {
        cout << "学生ID是:" << s_id << " 姓名是:" << s_name << endl;
    }
};

int main() {
    //创建具体学生
    student xiaoming;
    xiaoming.setid_name(5, "小明");
    xiaoming.showStudent();

    system("pause");
    return 0;
}
