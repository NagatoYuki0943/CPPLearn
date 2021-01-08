//身份的基类
//在整个系统中，有三种身份，分别为：学生代表、老师以及管理员
//三种身份有其共性也有其特性，因此我们可以将三种身份抽象出一个身份基类identity

#ifndef INC_07_IDENTITY_H
#define INC_07_IDENTITY_H

#pragma once

using namespace std;

#include <iostream>
#include <string>

//身份抽象类
class Identity {
public:
    //操作菜单基类 纯虚函数
    virtual void operMenu() = 0;

    //姓名
    string m_Name;

    //密码
    string m_Pwd;
};


#endif //INC_07_IDENTITY_H
