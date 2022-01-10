#include <iostream>
#include <string>

using namespace std;
//struct结构体是用户自定义的数据类型,允许用户存储不同的数据类型  注意:struct Student{};后面有 ;
/**
 * C++中struct和class唯一区别在于默认的访问权限不同
 * struct默认权限公开 public
 * class默认权限私有  private
 *      struct  里面的属性和方法也可以使用public,protected,private
 */
//1.创建结构体
struct Student {
    //成员列表
    string name;    //姓名
    int age;        //年龄
    int score;      //分数
} s3 = {"王五", 16, 70};
//2.3 在定义结构体时顺便创建结构体变量:

int main() {
    //2.通过学生类型创建具体学生     struct关键字可以省略,定义的时候不能省略

    //2.1 struct Student s1
    struct Student s1;       //通过 . 来访问内部数据
    s1.name = "张三", s1.age = 15, s1.score = 80;
    cout << "姓名:" << s1.name << " 年龄:" << s1.age << " 分数:" << s1.score << endl;

    //2.2 struct Student s2={}    //使用 , 分隔
    struct Student s2 = {"李四", 16, 85};  //使用 , 分隔
    cout << "姓名:" << s2.name << " 年龄:" << s2.age << " 分数:" << s2.score << endl;

    //2.3 在定义结构体时顺便创建结构体变量:上面
    cout << "姓名:" << s3.name << " 年龄:" << s3.age << " 分数:" << s3.score << endl;

    struct Student s4 = {"小兰", 15, 80};
    cout << "姓名:" << s4.name << " 年龄:" << s4.age << " 分数:" << s4.score << endl;

    return 0;
}
/**
 * 结构体和变量一样可以在函数内部和外部定义,外部定义的可以在全局访问,在函数内部定义的只能在函数内部使用
 * 结构体也可以初始化
 * Student st2={"小明",15,85}; 中间的 "=" 在c11之后可以省略
 */