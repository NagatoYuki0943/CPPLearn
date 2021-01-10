#include "manager.h"

//默认构造
Manager::Manager() {

}

//有参构造  管理员姓名，密码
Manager::Manager(string name, string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;

    //调用初始化学生和教师vector
    this->initVector();
    //调用初始化机房vector
    this->initComputer();
}


//选择菜单
void Manager::operMenu() {
    cout << "Welcome Admin : " << this->m_Name << " login !" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.Add Person          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.Show Person         |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.Show Computer       |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.Clear Order          |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.Exit                |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "Please input your choice :" << endl;
}


//添加账号
void Manager::addPerson() {

    string fileName;

    string tip;         //提示id
    string errorTip;    //重复错误提示
    ofstream ofs;       //文件输出流
    int select = 0;

    while (true) {
        cout << "Please input your account type" << endl;
        cout << "1,add a student" << endl;
        cout << "2,add a teacher" << endl;
        cin >> select;

        if (select == 1) {
            //学生
            fileName = STUDENT_FILE;
            tip = "Please input Id";
            errorTip = "Id duplicated,please input another id";
            break;
        } else if (select == 2) {
            //教师
            fileName = TEACHER_FILE;
            tip = "Please input Employee number";
            errorTip = "Employee number duplicated,please input another Employee number";
            break;
        }
    }

    //输出或者追加操作
    ofs.open(fileName, ios::out | ios::app);
    int id;         //学号,职工号
    string name;    //姓名
    string pwd;     //密码
    //输出提示
    cout << tip << endl;
    //输入id
    while (true) {
        cin >> id;
        bool res = checkRepeat(id, select);
        if (res) {
            //重复
            cout << errorTip << endl;
        } else {
            //没重复
            break;
        }
    }

    //姓名
    cout << "Please input name" << endl;
    cin >> name;
    //密码
    cout << "Please input password" << endl;
    cin >> pwd;
    //保存至文件
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Save successfully" << endl;

    ofs.close();

    //重新初始化容器,不然刚刚添加的人员没法被重复检测
    this->initVector();


    system("pause");
    system("cls");
}


//这两个方法不用在头文件中声明,直接使用就可,不然出错
//打印学生信息(普通函数)
void printStudent(Student &s) {
    cout << "id : " << s.m_Id << "\tname : " << s.m_Name << "\tpassword : " << s.m_Pwd << endl;
}


//打印教师信息(仿函数)
class printTeacher {
public:
    void operator()(Teacher &s) {
        cout << "Employee Number : " << s.m_EmpId << "\tname : " << s.m_Name << "\tpassword : " << s.m_Pwd << endl;
    }
};


//查看账号
void Manager::showPerson() {
    int select = 0;

    while (true) {
        cout << "Please Student or Teacher." << endl;
        cout << "1.Show all students" << endl;
        cout << "2.Show all teachers" << endl;

        cin >> select;
        if (select == 1) {
            for_each(vStu.begin(), vStu.end(), printStudent);
            break;
            //id : 1  name : zhangsan password : 123
            //id : 2  name : lisi     password : 123
            //id : 3  name : wangwu   password : 123
            //id : 4  name : perfume  password : 123
            //id : 5  name : Aimer    password : 123

        } else if (select == 2) {
            for_each(vTea.begin(), vTea.end(), printTeacher());
            break;
            //Employee Number : 1     name : laowang  password : 123
            //Employee Number : 2     name : laozhang password : 123
            //Employee Number : 3     name : milet    password : 123
            //Employee Number : 4     name : Harry    password : 123

        }
    }
    system("pause");
    system("cls");
    return;
}


//查看机房信息
void Manager::showComputer() {
    cout << "The information of the computer room is as follows :" << endl;
    for (vector<ComputerRoom>::iterator i = vCom.begin(); i != vCom.end(); ++i) {
        // *i 指的是vector<> <>里面的内容 i是一个指针
        cout << "Room number : " << (*i).m_ComId << "\tRoom Size : " << (*i).m_MaxNum << endl;
    }
    //The information of the computer room is as follows
    //Room number : 1 Room Size : 20
    //Room number : 2 Room Size : 50
    //Room number : 3 Room Size : 100

    system("pause");
    system("cls");
}


//清空预约记录
void Manager::cleanFile() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "Clear successfully" << endl;

    system("pause");
    system("cls");
}


//初始学生和教师化容器
void Manager::initVector() {
    //清空容器
    vStu.clear();
    vTea.clear();

    //读取学生文件中信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    //没有文件
    if (!ifs.is_open()) {
        cout << STUDENT_FILE << " open failed" << endl;
        return;
    }

    //创建学生对象存储临时文件
    Student s;
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
        //将取出的学生放入vStu vector
        vStu.push_back(s);
    }
    ifs.close();

    //cout << "Students' number is " << vStu.size() << " ." << endl;
    //Students' number is 3 .


    //读取教师文件中信息
    ifs.open(TEACHER_FILE, ios::in);
    //没有文件
    if (!ifs.is_open()) {
        cout << TEACHER_FILE << " open failed" << endl;
        return;
    }

    //创建教师对象存储临时文件
    Teacher t;
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
        //将取出的教师放入vStu vector
        vTea.push_back(t);
    }
    ifs.close();

    //cout << "Teachers' number is " << vStu.size() << " ." << endl;
    //Teachers' number is 3 .
}


//检测重复 参数:(传入id，传入类型type,1代表学生,2代表教师) 返回值：(true 代表有重复，false代表没有重复)
bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        //学生
        for (vector<Student>::iterator i = vStu.begin(); i != vStu.end(); ++i) {
            if (id == i->m_Id) {
                return true;
            }
        }
    } else {
        //老师
        for (int i = 0; i < vTea.size(); ++i) {
            if (id == vTea[i].m_EmpId) {
                return true;
            }
        }
    }

    //没有发现重复的,就返回false,不用在里面写
    return false;
}


//初始化机房信息
void Manager::initComputer() {
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


