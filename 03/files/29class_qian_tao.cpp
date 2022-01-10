#include <iostream>
#include <string>

using namespace std;

/**
 * c++中的成员可以使另一个类中的对象,成为对象成员
 * 先构造其他的class,后构造自己的class    先构建Phone,后构建person    先内后外
 * 先释放自己的class,后释放其他的class    先析构Person,后析构Phone    先外后内
 */
class Phone {
    //名字
public:
    Phone(string pName) : m_PName(pName) {
        cout << "Phone的构造函数调用" << endl;
    }

    ~Phone() {
        cout << "Phone的析构函数调用" << endl;
    }

    //品牌
    string m_PName;


};

class Person {
public:
    Person(string name, string pName) : m_Name(name), m_Phone(pName) { //后面相当于 Phone m_Phone=pName 隐式转换法
        cout << "Person的构造函数调用" << endl;
    }

    ~Person() {
        cout << "Person的析构函数调用" << endl;
    }

    //姓名
    string m_Name;
    //手机
    Phone m_Phone;
};

void test01() {
    Person p("小明", "苹果");
    cout << p.m_Name << "拿着" << p.m_Phone.m_PName << "手机" << endl;

}

int main() {
    test01();

    system("pause");
    return 0;
}
