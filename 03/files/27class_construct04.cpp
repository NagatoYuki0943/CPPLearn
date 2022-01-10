#include <iostream>

using namespace std;

/**
 * 浅拷贝:简单的赋值拷贝操作(默认的拷贝构造),复制指针,然后在释放的时候回释放两次,两次会报错(非法操作)
 * 深拷贝:在堆区重新申请空间(自己写拷贝构造函数),进行拷贝,深拷贝回让指针指向一个新的位置,里面的内容相同,就不会报错了(重新申请堆区内存空间进行复制)
 */

class Person {
public:
    //无参构造
    Person() {
        cout << "默认构造函数调用" << endl;
    }

    //有参构造
    Person(int age, int height) {
        m_Age = age;
        m_Height = new int(height); //在堆区创建变量
        cout << "有参构造函数调用" << endl;
    }

    //自己实现一个拷贝构造函数
    Person(const Person &p) {
        cout << "拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        //m_Height=p.m_Height; //编译器默认实现这行代码,有问题
        //深拷贝,重新申请空间
        m_Height = new int(*p.m_Height);  //注意解引用,m_Height是一个指针

    }

    //析构函数
    ~Person() {
        //析构代码,将堆区开辟的数据进行释放操作
        if (m_Height != NULL) {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "析构函数调用" << endl;
    }

    int m_Age;
    int *m_Height; //定义指针
};

void test01() {
    Person p1(18, 160);
    cout << "p1年龄:" << p1.m_Age << " p1身高:" << *p1.m_Height << endl;

    Person p2(p1);
    cout << "p2年龄:" << p2.m_Age << " p1身高:" << *p2.m_Height << endl;
}

int main() {
    test01();

    system("pause");
    return 0;
}
