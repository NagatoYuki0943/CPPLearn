#pragma once //防止重复包含
#include <istream>
using namespace std;
/**
 *   只声明,不实现
 */
//点类
class Point{
private:
    int m_X;
    int m_Y;
public:
    //设置x,y
    void setX_Y(int x,int y);
    //获取x
    int getX();
    //获取y
    int getY();
};