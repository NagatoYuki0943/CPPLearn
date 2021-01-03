#include <iostream>

using namespace std;
/**
 * 菱形继承:两个派生类继承同一个基类,又有某个类同时继承这两个派生类,成为菱形继承或者钻石💎继承
 *  利用虚继承可以解决菱形继承的问题,在继承的方式之前加上virtual关键字,Animal类成为虚基类
 */
//动物类
class Animal {
public:
    int m_Age;
};

///利用虚继承可以解决菱形继承的问题,
///在继承的方式之前加上virtual关键字,
///Animal类成为虚基类
//羊
class Sheep : virtual public Animal {
};

//骆驼
class Camel : virtual public Animal {
};

class YangTuo : public Sheep, public Camel {

};

void test01() {
    YangTuo st;
    //st.m_Age=18;  //报错,分别从羊和骆驼继承了两份,不知道确切是哪一个
    st.Sheep::m_Age = 18;
    st.Camel::m_Age = 28;
    //当出现菱形继承的时候,有两个父类拥有相同的数据,需要加以作用域区分
    cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;  //使用虚继承之后,两行的输出都是28,先赋值18,在赋值28
    cout << "st.Camel::m_Age=" << st.Camel::m_Age << endl;
    cout << "st.m_Age=\t" << st.m_Age << endl;                ///可以使用这种方式访问了

    //这份数据只要有一个就可以了,菱形继承导致数据有两份,资源浪费

}

int main() {
    test01();
    system("pause");
    return 0;
}