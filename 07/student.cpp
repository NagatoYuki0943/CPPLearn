#include "student.h"

//默认构造
Student::Student() {

}

//有参构造(学号,姓名,密码)
Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    //初始化机房信息
    this->initComputer();
}

//菜单界面
void Student::operMenu() {
    cout << "Welcome student " << this->m_Name << " login!" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1.Apply order          |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2.show my orders       |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3.show all orders      |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4.cancel order         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0.exit                 |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "Please input your choice :" << endl;
}

//申请预约
void Student::applyOrder() {
    cout << "The computer room is open from Monday to Friday" << endl;
    cout << "Please enter the time of applying for an appointment" << endl;
    cout << "1.Monday" << endl;
    cout << "2.Tuesday" << endl;
    cout << "3.Wednesday" << endl;
    cout << "4.Thursday" << endl;
    cout << "5.Friday" << endl;
    int date = 0;       //日期
    int interval = 0;   //时间段,上午,下午
    int room = 0;       //房间号

    //输入日期
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }

        //输入错误,提示用户
        cout << "Please input number greater than 1 and less than 5" << endl;

    }

    cout << "Please enter the time period for applying for an appointment" << endl;
    cout << "1.morning" << endl;
    cout << "2.afternoon" << endl;

    //输入时间段
    while (true) {
        cin >> interval;
        if (interval == 1 || interval == 2) {
            break;
        }
        cout << "Interval input error,Please input 1(morning) or 2(afternoon)" << endl;
    }


    cout << "PLease choose ComputerRoom" << endl;
    for (int i = 0; i < vCom.size(); ++i) {
        cout << "Number " << i + 1 << " Room's capacity is " << vCom[i].m_MaxNum << endl;
    }
    //PLease choose ComputerRoom
    //Number 1 Room's capacity is 20
    //Number 2 Room's capacity is 50
    //Number 3 Room's capacity is 100


    //选择机房
    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "Please input correct room number,1 or 2 or 3." << endl;
    }

    cout << "Appointment successful! Under review" << endl;

    //附加形式打开文件
    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;     //1代表审核

    ofs.close();

    system("pause");
    system("cls");

}

//查看我的预约
void Student::showMyOrder() {

    //orderFile可以获取order中的信息
    OrderFile of;
    //查看全部的预约信息
    if (of.m_Size == 0) {
        cout << "There are no orders" << endl;
        system("pause");
        system("cls");
        return;
    }

    //自己的预约
    bool MyOrder = false;

    for (int i = 0; i < of.m_Size; ++i) {
        //string 转 int 步骤 1, .c_str() 转为 char *  2, 利用 atoi(const char *) 转换为 int

        //只有是自己的id才输出
        if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {
            //有我的预约
            MyOrder = true;

            cout << "Date : " << of.m_OrderData[i]["date"] << ",\t";
            cout << "Interval : " << (of.m_OrderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << ",\t";
            cout << "ComputerRoom : " << of.m_OrderData[i]["roomId"] << ",\t";
            //预约状态
            string status = "status : ";    //状态  0 取消的预约 1 审核中 2 已预约 -1 预约失败
            if (of.m_OrderData[i]["status"] == "1") {         //1 审核中
                status += "Under review";

            } else if (of.m_OrderData[i]["status"] == "2") {   //2 已预约
                status += "Order successful";

            } else if (of.m_OrderData[i]["status"] == "-1") {  //-1 预约失败
                status += "Audit failed, order failed";

            } else {                                          //0 取消的预约
                status += "Order has been canceled";
            }
            cout << status << endl;
        }
        //Date : 5,       Interval : Afternoon,   ComputerRoom : 3,       status : Under review
        //Date : 1,       Interval : Morning,     ComputerRoom : 2,       status : Under review
    }

    //没有自己的预约就输出这一句
    if (MyOrder == false) {
        cout << "There is no order for you" << endl;
    }

    system("pause");
    system("cls");
}


//查看所有预约
void Student::showAllOrder() {
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
        if (of.m_OrderData[i]["status"] == "1") {         //1 审核中
            status += "Under review";

        } else if (of.m_OrderData[i]["status"] == "2") {   //2 已预约
            status += "Order successful";

        } else if (of.m_OrderData[i]["status"] == "-1") {  //-1 预约失败
            status += "Audit failed, order failed";

        } else {                                          //0 取消的预约
            status += "Order has been canceled";
        }
        cout << status << endl;
    }
    //1, Date : 5,    Interval : Afternoon,   Students ID : 1,        Students name : zhangsan,       ComputerRoom : 3,      status : Under review
    //2, Date : 2,    Interval : Afternoon,   Students ID : 2,        Students name : lisi,           ComputerRoom : 2,      status : Under review
    //3, Date : 1,    Interval : Morning,     Students ID : 1,        Students name : zhangsan,       ComputerRoom : 2,      status : Under review
    //4, Date : 3,    Interval : Afternoon,   Students ID : 1,        Students name : zhangsan,       ComputerRoom : 3,      status : Under review

    system("pause");
    system("cls");
}

//取消预约
void Student::cancelOrder() {
    OrderFile of;

    //查看全部的预约信息
    if (of.m_Size == 0) {
        cout << "There are no orders" << endl;
        system("pause");
        system("cls");
        return;
    }

    //存放可以修改的i值
    vector<int> v;

    //目录
    int index = 1;

    //审核中或预约成功的记录可以取消，请输入取消的记录"
    cout << "Records under review or with successful appointment "
            "can be cancelled. Please enter the cancelled record" << endl;
    for (int i = 0; i < of.m_Size; ++i) {
        //string 转 int 步骤 1, .c_str() 转为 char *  2, 利用 atoi(const char *) 转换为 int

        //只有是自己的id才输出
        if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id) {

            if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2") {

                //将行数下标放入v
                v.push_back(i);

                //输出编号
                cout << index++ << ", ";

                cout << "Date : " << of.m_OrderData[i]["date"] << ",\t";
                cout << "Interval : " << (of.m_OrderData[i]["interval"] == "1" ? "Morning" : "Afternoon") << ",\t";
                cout << "ComputerRoom : " << of.m_OrderData[i]["roomId"] << ",\t";
                //预约状态
                string status = "Status : ";    //状态  0 取消的预约 1 审核中 2 已预约 -1 预约失败
                if (of.m_OrderData[i]["status"] == "1") {         //1 审核中
                    status += "Under review";

                } else if (of.m_OrderData[i]["status"] == "2") {   //2 已预约
                    status += "Order successful";

                }

                cout << status << endl;

                //Date : 5,       Interval : Afternoon,   ComputerRoom : 3,       status : Under review
                //Date : 1,       Interval : Morning,     ComputerRoom : 2,       status : Under review
            }
        }
    }

    cout << "Please enter the cancelled record. 0 means return" << endl;

    int select = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                //select是从1开始计数,vector是从0开始计数,所以要 -1
                cout << "Records' location is " << v[select - 1] << endl;
                //vector<int> v中存放的是真实的行数
                of.m_OrderData[v[select - 1]]["status"] = "0";
                of.updateOrder();
                cout << "Order cancelled" << endl;
                break;
            }
        }
        cout << "Input error,please input again" << endl;
    }

    system("pause");
    system("cls");
}

//初始化机房信息
void Student::initComputer() {
    //清空机房信息
    vCom.clear();

    //获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    //未打开
    if (!ifs.is_open()) {
        cout << COMPUTER_FILE << " open failed" << endl;
        return;
    }

    ComputerRoom c;
    while (ifs >> c.m_ComId, ifs >> c.m_MaxNum) {
        vCom.push_back(c);
    }
    ifs.close();

    //cout << "This has " << vCom.size() << " computer rooms." << endl;
    //This has 3 computer rooms.
}