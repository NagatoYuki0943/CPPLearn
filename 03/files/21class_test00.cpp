#include <iostream>

using namespace std;

/**
 * cube类,求立方体的体积和面积
 * 分别用全局函数和成员函数判断两个立方体是否相等
 */
class Cube {
    //默认私有
    int m_l, m_w, m_h;
public:
    //设置长宽高
    void set_lmh(int l, int w, int h) {
        m_l = l;
        m_w = w;
        m_h = h;
    }

    //返回长宽高
    int getL() {
        return m_l;
    }

    int getW() {
        return m_w;
    }

    int getH() {
        return m_h;
    }

    //面积
    int calculateArea() {
        return 2 * (m_l * m_w + m_l * m_h + m_w * m_h);
    }

    //体积
    int calculateVolume() {
        return m_l * m_w * m_h;
    }

    //利用成员函数判断两个立方体是否相等
    //只用传入一个Cube即可,因为这个类中有一个Cube了
    bool isSame00(Cube &c1) {  //引用传递,节省内存
        if (c1.m_l == m_l && c1.m_w == m_w && c1.m_h == m_h) {
            return true;
        } else {
            return false;
        }
    }
};

//利用全局函数判断两个立方体是否相等
bool isSamebyClass(Cube &c1, Cube &c2) {  //引用传递,节省内存
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
        return true;
    } else {
        return false;
    }
};

int main() {
    Cube c1;
    //设置长宽高
    c1.set_lmh(10, 20, 30);
    cout << "面积是:" << c1.calculateArea() << endl;  //2200
    cout << "体积是:" << c1.calculateVolume() << endl;//6000
    Cube c2;
    c2.set_lmh(10, 20, 30);
    //使用全局函数
    cout << "全局函数判断:\t" << (isSamebyClass(c1, c2) == true ? "相等" : "不相等") << endl;
    //使用成员函数,只需要传入一个
    cout << "成员函数判断:\t" << (c2.isSame00(c1) == true ? "相等" : "不相等") << endl;

    system("pause");
    return 0;
}

/*bool isSame00(Cube &c1,Cube &c2){  //引用传递,节省内存
    if(c1.m_l==c2.m_l && c1.m_w==c2.m_w && c1.m_h==c2.m_h){
        return true;
    }else{
        return false;
    }
}*/
