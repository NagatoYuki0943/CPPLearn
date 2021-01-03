#include <iostream>
#include "22class_test01.point.h"
#include "22class_test01.circle.h"

using namespace std;
/**
 * 类中可以让另一个类作为本类中的成员
 */
/**
 * 分别放入不同的文件中
 */

//判断点和圆的关系
void isInCircle(Circle &c, Point &i) {
    //计算两点之间距离的平方 (x2,y2),(x1-x2)^2+(y1-y2)^2
    int l1 = (c.getCenter().getX() - i.getX()) * (c.getCenter().getX() - i.getX()) +
             (c.getCenter().getY() - i.getY()) * (c.getCenter().getY() - i.getY());
    //半径的平方
    int l2 = c.getR() * c.getR();
    //判断
    if (l1 > l2) {
        //在圆外
        cout << "点在圆外" << endl;
    } else if (l1 == l2) {
        //在圆上
        cout << "点在圆上" << endl;
    } else {
        //在圆内
        cout << "点在圆内" << endl;
    }
}

int main() {
    //创建圆
    Circle c;
    //圆心
    Point c0;
    c0.setX_Y(0, 0);  //圆心是(0,0)
    c.setCenter(c0);
    //圆半径
    c.setR(1);          //半径是1

    //点
    Point p1, p2, p3;
    p1.setX_Y(1, 0);    //上
    p2.setX_Y(2, 0);    //外
    p3.setX_Y(0, 0);    //内
    isInCircle(c, p1); //上
    isInCircle(c, p2); //外
    isInCircle(c, p3); //内





    system("pause");
    return 0;
}
