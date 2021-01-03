#include "22class_test01.point.h"

//设置x,y
void Point::setX_Y(int x, int y) {
    m_X = x;
    m_Y = y;
}

//获取x
int Point::getX() {
    return m_X;
}

//获取y
int Point::getY() {
    return m_Y;
}
