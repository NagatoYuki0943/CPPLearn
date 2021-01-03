#include "22class_test01.circle.h"
//圆类



//设置半径
void Circle::setR(int r) {
    m_R = r;
}

//获取半径
int Circle::getR() {
    return m_R;
}

//设置圆心,类中可以让另一个类作为本类中的成员
void Circle::setCenter(Point center) {
    m_Center = center; //直接赋值就可以,不用赋值center里面的东西
}

//获取圆心
Point Circle::getCenter() {
    return m_Center;
}
