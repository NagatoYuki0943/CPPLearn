#include "teacher.h"

//默认构造
Teacher::Teacher() {

}

//有参构造(职工编号,姓名,密码)
Teacher::Teacher(int empId, string name, string pwd) {
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu() {
    cout << "Welcome teacher " << this->m_Name << " login!" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.Show all orders       |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.Review orders         |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.Exit                  |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "Please input your choice : " << endl;
}

//查看所有预约
void Teacher::showAllOrder() {
    //orderFile可以获取order中的信息
    OrderFile of;

    //查看全部的预约信息
    if (of.m_Size == 0) {
        cout << "There are no orders" << endl;
        system("pause");
        system("cls");
        return;
    }

    //全部输出
    for (int i = 0; i < of.m_Size; ++i) {

        cout << i + 1 << ", ";

        cout << "Date : " << of.m_OrderData[i]["date"] << ",\t";
        cout << "Interval : " << (of.m_OrderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << ",\t";
        cout << "Students ID : " << of.m_OrderData[i]["stuId"] << ",\t";
        cout << "Students name : " << of.m_OrderData[i]["stuName"] << ",\t";
        cout << "ComputerRoom : " << of.m_OrderData[i]["roomId"] << ",\t";
        //预约状态
        string status = "Status : ";    //状态  0 取消的预约 1 审核中 2 已预约 -1 预约失败
        if (of.m_OrderData[i]["status"] == "1") {           //1 审核中
            status += "Under review";

        } else if (of.m_OrderData[i]["status"] == "2") {    //2 已预约
            status += "Order successful";

        } else if (of.m_OrderData[i]["status"] == "-1") {   //-1 预约失败
            status += "Order failed";

        } else {                                            //0 取消的预约
            status += "Order has been canceled";
        }
        cout << status << endl;
    }

    system("pause");
    system("cls");
}


//审核预约
void Teacher::validOrder() {
    //OrderFile是专门修改文件的
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "There are no orders" << endl;
        system("pause");
        system("cls");
        return;
    }

    //待审核的预约记录如下
    cout << "The order records to be reviewed are as follows :" << endl;

    //存放待审核的下标(行数)
    vector<int> v;
    //目录
    int index = 0;

    for (int i = 0; i < of.m_Size; ++i) {
        if (of.m_OrderData[i]["status"] == "1") {   //状态  0 取消的预约 1 审核中 2 已预约 -1 预约失败
            //将待批阅的行数放入v
            v.push_back(i);
            cout << ++index << ", ";
            cout << "Date : " << of.m_OrderData[i]["date"] << ",\t";
            cout << "Interval : " << of.m_OrderData[i]["interval"] << ",\t";
            cout << "Students ID : " << of.m_OrderData[i]["stuId"] << ",\t";
            cout << "Students name : " << of.m_OrderData[i]["stuName"] << ",\t";
            cout << "SComputerRoom : " << of.m_OrderData[i]["roomId"] << ",\t";
            cout << "Status : Under review" << endl;
        }
    }
    //1, Date : 2,    Interval : 2,   Students ID : 2,        Students name : lisi,   SComputerRoom : 2,      Status : Under review
    //2, Date : 1,    Interval : 1,   Students ID : 1,        Students name : zhangsan,       SComputerRoom : 2,      Status : Under review
    //3, Date : 3,    Interval : 2,   Students ID : 1,        Students name : zhangsan,       SComputerRoom : 3,      Status : Under review


    //请输入审核的预约记录,0代表返回
    cout << "Please enter the approved order record. 0 means return" << endl;
    int select = 0;
    int res = 0;

    while (true) {
        cin >> select;
        //在范围内才修改
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                //退出
                break;
            } else {
                //输出的是index,使用select保存的,下面直接修改对应的行的status的数字
                while (true) {
                    //请输入审核结果
                    cout << "Please input findings of audit" << endl;
                    cout << "1.Pass" << endl;
                    cout << "2.Go die" << endl;
                    cin >> res;
                    if (res == 1) {       //状态  0 取消的预约 1 审核中 2 已预约 -1 预约失败
                        //通过, 2
                        //select从1开始数,vector下标从0开始,所以要减一得到正确的位置,然后取出v中的值,取出的是就是正确的行数,进行修改即可
                        of.m_OrderData[v[select - 1]]["status"] = "2";
                        break;
                    } else if (res == 2) {
                        //不通过, -1
                        of.m_OrderData[v[select - 1]]["status"] = "-1";
                        break;
                    }
                }
                of.updateOrder();
                cout << "Approve over." << endl;
                break;
            }
        }

        cout << "Input error,please input 0 or record number" << endl;
    }

    system("pause");
    system("cls");
}