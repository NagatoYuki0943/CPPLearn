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
    ofs << "date : " << date << " ";
    ofs << "interval : " << interval << " ";
    ofs << "stuId : " << this->m_Id << " ";
    ofs << "stuName : " << this->m_Name << " ";
    ofs << "roomId : " << room << " ";
    ofs << "status : " << 1 << endl;     //1代表审核

    ofs.close();

    system("pause");
    system("cls");

}

//查看我的预约
void Student::showMyOrder() {

}

//查看所有预约
void Student::showAllOrder() {

}

//取消预约
void Student::cancelOrder() {

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