#pragma once //防止重复包含
#include <iostream>
#include "22class_test01.point.h"
using namespace std;
/**
 *   只声明,不实现
 */
//圆类
class Circle{
private:
    int m_R; //半径
    Point m_Center;// 圆心
public:
    //设置半径
    void setR(int r);
    //获取半径
    int getR();
    //设置圆心,类中可以让另一个类作为本类中的成员
    void setCenter(Point center);
    //获取圆心
    Point getCenter();
};