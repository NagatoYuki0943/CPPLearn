//管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录
//管理员类中主要功能有：
//  显示管理员操作的菜单界面
//  添加账号
//  查看账号
//  查看机房信息
//  清空预约记录

#ifndef INC_07_MANAGER_H
#define INC_07_MANAGER_H

#pragma once

#include "identity.h"

class Manager : public Identity {
public:

    //默认构造
    Manager();

    //有参构造  管理员姓名，密码
    Manager(string name, string pwd);

    //选择菜单
    void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

};


#endif //INC_07_MANAGER_H
