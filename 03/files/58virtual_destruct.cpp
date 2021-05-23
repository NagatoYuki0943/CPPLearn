#include <iostream>
#include <string>

using namespace std;
/**
 * 多态使用时,如果子类中有属性开辟到堆区,那么父类指针在释放时无法调用到子类的析构代码
 * 解决方式:将父类中的析构函数改为虚析构或者纯虚析构
 */
/**
 * 虚析构和纯虚析构的共性:
 *     1.可以解决父类指针释放子类对象
 *     2.都需要有具体的函数实现(有函数体)
 * 区别:
 *     如果是纯虚析构,该类属于抽象类,无法实例化对象
 * 虚析构语法:
 *     virtual ~类名(){}
 * 纯虚析构语法:
 *     virtual ~类名()=0;
 * 类外实现: 类名::~类名(){}
 */
class Animal {
public:
    Animal() {
        cout << "Animal的构造函数调用" << endl;
    }
    ///加上虚析构之后,子类和父类的析构函数就都会调用了,可以解决父类指针释放子类对象时释放不干净的问题
    /*virtual ~Animal(){
        cout << "Animal的虚析构函数调用" << endl;
    }*/
    /**
     * 纯虚析构 (需要声明和实现)
     * 有了纯虚析构之后,这个类属于抽象类,无法实例化
     * 会报错,因为析构函数必须有实现,这样写没有实现,在外部实现以下就可以了
     */
    virtual ~Animal() = 0;

    virtual void Speak() = 0;
};

Animal::~Animal() {
    cout << "Animal的纯虚析构函数调用" << endl;
}


class Cat : public Animal {
public:
    explicit Cat(string name) {
        cout << "Cat的构造函数调用" << endl;
        m_Name = new string(name);
    }

    ~Cat() override {///默认不会调用这个析构函数
        //销毁堆区数据
        if (m_Name != NULL) {
            cout << "Cat的析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }

    void Speak() override {
        cout << *m_Name << "在说话" << endl;
    }

    string *m_Name;
};

void test01() {
    Animal *animal = new Cat("Tom猫");
    animal->Speak();
    ///父类指针在析构的时候 不会调用子类中析构函数 导致子类如果有堆区属性,会出现内存泄漏
    delete animal;
}

int main() {
    test01();
    system("pause");
    return 0;
}