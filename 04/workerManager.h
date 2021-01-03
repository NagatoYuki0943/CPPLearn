#pragma once  //防止头文件重复包含
#include<iostream>
#include<fstream>
#define FILENAME "empFile.txt"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

class WorkerManager {
public:
    //构造函数
    WorkerManager();
    //析构函数
    ~WorkerManager();
    //展示菜单函数
    void Show_Menu();
    //退出功能
    void ExitSystem();
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker** m_EmpArray;
    //添加职工函数
    void Add_Emp();
    //保存文件
    void save();
    //判断文件是否为空标志
    bool m_FileIsEmpty;
    //统计人数
    int get_EmpNum();
    //初始化员工
    void init_Emp();
    //显示员工
    void Show_Emp();
    //判断员工是否存在,如果存在,返回职工所在数组位置,不存在返回-1
    int IsExist(int id);
    //删除员工
    void Del_Emp();
    //修改职工
    void Mod_Emp();
    //查找职工
    void Find_Emp();
    //按照编号排序
    void Sort_Emp();
    //清空文件
    void Clean_File();
    //将输入的id与已经存在的id进行比较
    bool Compare_Id(int id);
};
