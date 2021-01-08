//学生类主要功能是可以通过类中成员函数，实现预约实验室操作
//学生类中主要功能有：
//  显示学生操作的菜单界面
//  申请预约
//  查看自身预约
//  查看所有预约
//  取消预约

#ifndef INC_07_STUDENT_H
#define INC_07_STUDENT_H

#pragma once

#include "identity.h"


class Student : public Identity {
public:
    //默认构造
    Student();

    //有参构造(学号,姓名,密码)
    Student(int id, string name, string pwd);

    //菜单界面

    void operMenu();

    //申请预约
    void applyOrder();

    //查看我的预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学号
    int m_Id;

};


#endif //INC_07_STUDENT_H
