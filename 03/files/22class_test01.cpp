#include <iostream>
#include "22class_test01.point.h"
#include "22class_test01.circle.h"

using namespace std;
/**
 * ���п�������һ������Ϊ�����еĳ�Ա
 */
/**
 * �ֱ���벻ͬ���ļ���
 */

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle &c, Point &i) {
    //��������֮������ƽ�� (x2,y2),(x1-x2)^2+(y1-y2)^2
    int l1 = (c.getCenter().getX() - i.getX()) * (c.getCenter().getX() - i.getX()) +
             (c.getCenter().getY() - i.getY()) * (c.getCenter().getY() - i.getY());
    //�뾶��ƽ��
    int l2 = c.getR() * c.getR();
    //�ж�
    if (l1 > l2) {
        //��Բ��
        cout << "����Բ��" << endl;
    } else if (l1 == l2) {
        //��Բ��
        cout << "����Բ��" << endl;
    } else {
        //��Բ��
        cout << "����Բ��" << endl;
    }
}

int main() {
    //����Բ
    Circle c;
    //Բ��
    Point c0;
    c0.setX_Y(0, 0);  //Բ����(0,0)
    c.setCenter(c0);
    //Բ�뾶
    c.setR(1);          //�뾶��1

    //��
    Point p1, p2, p3;
    p1.setX_Y(1, 0);    //��
    p2.setX_Y(2, 0);    //��
    p3.setX_Y(0, 0);    //��
    isInCircle(c, p1); //��
    isInCircle(c, p2); //��
    isInCircle(c, p3); //��





    system("pause");
    return 0;
}
