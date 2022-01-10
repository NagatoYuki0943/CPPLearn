#include <iostream>
#include <string>

using namespace std;

/**
 * 成员属性设置为私有
 * 好处:
 *      1.可以自己控制读写权限
 *      2.对于写,可以检测数据的有效性,可以使用判断语句进行控制赋值
 */
class Person {
    //姓名 可读可写
    string m_Name;
    //年龄 可读可写
    int m_Age = 10;
    //情人 只写
    string m_Lover;
public:
    //设置姓名可读可写
    void setName(string name) {
        m_Name = name;
    }

    string getName() {
        return m_Name;
    }

    //年龄 设置 0-150
    void setAge(int age) {
        if (age < 0 || age > 150) {
            cout << "老妖精或者没出生" << endl;
            return;
        }
        m_Age = age;
    }

    //年龄 获取
    int getAge() {
        return m_Age;
    }

    //情人 只写
    void setLover(string Lover) {
        m_Lover = Lover;
    }
};

int main() {
    Person p1;
    //姓名
    p1.setName("小红");
    cout << "姓名是" << p1.getName() << endl;
    //年龄,不能直接更改,是private
    p1.setAge(110);
    cout << "年龄是" << p1.getAge() << endl;
    //情人
    p1.setLover("仓井");


    system("pause");
    return 0;
}
