//教师类主要功能是查看学生的预约，并进行审核
//教师类中主要功能有：
//显示教师操作的菜单界面
//查看所有预约
//审核预约

#ifndef INC_07_TEACHER_H
#define INC_07_TEACHER_H

#pragma ocne

#include "identity.h"

class Teacher : public Identity {
public:
    //默认构造
    Teacher();

    //有参构造(职工编号,姓名,密码)
    Teacher(int empId, string name, string pwd);

    //菜单界面
    void operMenu() override;

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    //教师编号
    int m_EmpId;
};

#endif //INC_07_TEACHER_H
