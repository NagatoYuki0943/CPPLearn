#include "boss.h"
//构造函数
Boss::Boss(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}
//显示个人信息
void Boss::showInfo() {
    cout << "职工编号:" << this->m_Id << "\t";
    cout << "职工姓名:" << this->m_Name << "\t";
    cout << "职工岗位:" << this->getDepName() << "\t";
    cout << "岗位职责:管理公司所有事务" << endl;
}
//获取岗位名称
string Boss::getDepName() {
    return string("老板");
}