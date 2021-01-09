#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include "orderFile.h"

using namespace std;

//管理员子菜单
//在机房预约系统.cpp中，当用户登录的是管理员，添加管理员菜单接口
//将不同的分支提供出来
//  添加账号
//  查看账号
//  查看机房
//  清空预约
//  注销登录
//  实现注销功能
//Identity * &manager 传入的是manager,用Identity类型的指针保存
void managerMenu(Identity *&manager) {
    while (true) {
        //管理员菜单
        manager->operMenu();
        //将父类指针转为子类指针,为了调用子类里私有接口
        Manager *man = (Manager *) manager;

        int select = 0;
        //接收用户选择
        cin >> select;
        if (select == 1) {             //添加账号
            cout << "Add Person" << endl;
            man->addPerson();

        } else if (select == 2) {      //查看账号
            cout << "Show Person" << endl;
            man->showPerson();

        } else if (select == 3) {      //查看机房
            cout << "Show Computer" << endl;
            man->showComputer();

        } else if (select == 4) {      //清空预约
            cout << "Clear File" << endl;
            man->cleanFile();

        } else if (select == 0) {
            //销毁堆区对象
            delete manager;
            cout << "Exit successfully" << endl;
            system("pause");
            system("cls");
            return;

        } else {
            //清空,上面会重新显示菜单
            system("cls");
        }
    }
}


//机房预约系统.cpp中，当用户登录的是学生，添加学生菜单接口
//将不同的分支提供出来
//  申请预约
//  查看我的预约
//  查看所有预约
//  取消预约
//  注销登录
//  实现注销功能
//Identity * &manager 传入的是manager,用Identity类型的指针保存
void studentMenu(Identity *&student) {
    while (true) {
        //学生子菜单
        student->operMenu();

        Student *stu = (Student *) student;
        int select = 0;
        cin >> select;
        if (select == 1) {        ////申请预约
            stu->applyOrder();
            break;

        } else if (select == 2) {
            stu->showMyOrder();
            break;

        } else if (select == 3) {
            stu->showAllOrder();
            break;

        } else if (select == 4) {
            stu->cancelOrder();
            break;

        } else if (select == 0) {
            //销毁堆区对象
            delete student;
            cout << "Exit successfully" << endl;
            system("pause");
            system("cls");
            return;

        } else {
            //清空,上面会重新显示菜单
            system("cls");
        }
    }
}


//login登录功能,参数1:操作文件名称;参数2:操作人类型
void LoginIn(string fileName, int type) {

    //多态,父类指针,用于指向子类对象
    Identity *person = NULL;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    //判断文件是否存在
    if (!ifs.is_open()) {
        cout << fileName << " is not exist" << endl;
        ifs.close();
        return;
    }

    //准备接收用户信息
    int id = 0;
    string name;
    string pwd;

    //判断身份
    if (type == 1) {
        //学生
        cout << "Please input your id :" << endl;
        cin >> id;
    } else if (type == 2) {
        //教师
        cout << "Please input your employee number :" << endl;
        cin >> id;
    }


    //输入姓名,密码
    cout << "Please input you account name :" << endl;
    cin >> name;
    cout << "Please input password :" << endl;
    cin >> pwd;


    if (type == 1) {
        //学生登录验证

        //从文件中获取的id,姓名,密码
        int fId;
        string fName;
        string fPwd;
        //ifs >> 默认使用空格作为分隔,文件中就是这样的,所以可以获取一行的信息,一次性获取一行
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //cout << fId << " " << fName << " " << fPwd << endl;
            //1 zhangsan 123456
            //2 lisi 123456

            //于用户获取的信息做对比
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "Student login successfully" << endl;
                system("pause");
                system("cls");
                //父类指针指向子类(多态要使用父类的指针或者引用指向子类,不然不能用)
                person = new Student(id, name, pwd);

                //进入学生子菜单
                studentMenu(person);
                return;
            }
        }
    } else if (type == 2) {
        //教师登录验证

        //从文件中获取的id,姓名,密码
        int fId;
        string fName;
        string fPwd;
        //ifs >> 默认使用空格作为分隔,文件中就是这样的,所以可以获取一行的信息,一次性获取一行
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            //cout << fId << " " << fName << " " << fPwd << endl;
            //1 laowang 123456

            //于用户获取的信息做对比
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "Teacher login successfully" << endl;
                system("pause");
                system("cls");
                //父类指针指向子类(多态要使用父类的指针或者引用指向子类,不然不能用)
                person = new Teacher(id, name, pwd);

                //进入教师子菜单

                return;
            }
        }


    } else if (type == 3) {
        //管理员登录验证

        //从文件中获取的姓名,密码
        string fName;
        string fPwd;
        //ifs >> 默认使用空格作为分隔,文件中就是这样的,所以可以获取一行的信息,一次性获取一行
        while (ifs >> fName && ifs >> fPwd) {
            //cout << fName << " " << fPwd << endl;
            //admin 123456

            //于用户获取的信息做对比
            if (name == fName && pwd == fPwd) {
                cout << "Manager login successfully" << endl;
                system("pause");
                system("cls");
                //父类指针指向子类(多态要使用父类的指针或者引用指向子类,不然不能用)
                person = new Manager(name, pwd);

                //进入管理员子菜单
                managerMenu(person);
                return;
            }
        }

    }
    cout << "Login failed" << endl;
    system("pause");
    system("cls");
    return;
}


int main() {

    //用于接收用户的选择
    int select = 0;
    while (true) {
        cout << "======================  Welcome to the computer room reservation system  ====================="
             << endl;
        cout << endl << "Please input your identity : " << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.Student            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.Teacher            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.Administrator      |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.Exit               |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "Please input your choice : ";

        cin >> select;

        switch (select) {
            case 1:     //1.Student
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2:     //2.Teacher
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3:     //3.Administrator
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0:     //0.Exit
                cout << "See you next time" << endl;
                system("pause");
                exit(0);   //exit(0) 和 return ;效果类似,exit(0) 会关闭整个程序,而return ;是返回上一级
                return 0;
            default:
                cout << "Input error,please input again" << endl;
                system("pause");
                system("cls");
                break;
        }
    }


    system("pause");

    return 0;
}
