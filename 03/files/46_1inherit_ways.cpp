#include <iostream>

using namespace std;
/**
 * class 子类 : 继承方式 父类
 * 继承方式   公共继承:public:
 *          保护继承:protected:
 *          私有继承:private:
 *
 * 父类中的private子类无论什么继承都不能访问(只是被隐藏了,也会继承下去)
 * public继承,父类的public和protected都不发生改变
 * protected继承,父类的public和protected都变为protected权限
 * private继承,父类的public和protected都变为private权限
 */

/**
 * C++中私有属性/方法被继承后不能直接访问
 *      C++父类的私有属性/方法,子类能继承,但是子类不能直接访问,需要使用父类提供的方法才能访问该属性/方法.可以从继承中得到的protected、public方法来访问
 * C#中私有属性/方法被继承后不能直接访问
 *      C#父类的私有属性/方法,子类能继承,但是子类不能直接访问,需要使用父类提供的方法才能访问该属性/方法.可以从继承中得到的protected、public方法来访问
 * PHP中继承时子类继承父类所有的公有成员,受保护成员和私有属性(不能直接访问),不能继承子类的私有方法
 *      PHP父类的私有属性子类能继承,私有方法不能被继承(后面方法可以访问),需要使用父类提供的方法才能访问该属性/方法.可以从继承中得到的protected、public方法来访问

/**
 * C++子类继承不能继承父类的构造函数
 * C#子类继承不能继承父类的构造函数
 * PHP构造方法也可以被继承(php中构造方法是普通方法,遵循普通方法规律),因此实例化子类对象的时候,要考虑父类构造方法所使用的参数问题
 */

//继承方式
class Base1 {
public:
    int m_A;
protected:
    int m_B;
private:
    //私有属性/方法都不能被继承
    int m_C;

    int showNum() {
        return 1;
    }
};

//公共方式继承
class Son1 : public Base1 {
    void func() {
        m_A = 10;    //父类public权限在子类中依然是public权限
        m_B = 20;    //protected权限在子类中依然是protected权限
        //m_C=30;  //父类中private权限子类不能访问
    }

};

void test01() {
    Son1 s1;
    s1.m_A = 100;    //public权限在类外可以访问
    //s1.m_B=200;  //protected权限在类外不能访问
}

//保护继承
class Son2 : protected Base1 {
    void func() {
        m_A = 10;    //public权限变为protected权限了
        m_B = 20;    //protected权限在子类中依然是protected权限
        //m_C=30;  //父类中private权限子类不能访问
    }
};

void test02() {
    Son2 s2;
    //s2.m_A=100;  //public权限变为protected权限了
    //s2.m_B=200;  //protected权限在类外不能访问
}

//私有继承
class Son3 : private Base1 {
    void func() {
        m_A = 10;    //public权限变为private权限了
        m_B = 20;    //protected权限在子类中变为private权限
        //m_C=30;  //父类中private权限子类不能访问
    }
};

void test03() {
    Son3 s3;
    //s3.m_A=100;  //public权限变为private权限了
    //s3.m_B=200;  //protected权限在类外不能访问
}

class GrandSon : public Son3 {
    void func1() {
        //m_A=1000;  //到了son3中,所有成员全变为private方式,子类不能继承
        //m_B=1000;
        //m_C=1000;
    }
};

int main() {
    return 0;
}