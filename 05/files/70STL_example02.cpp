#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;
/**
 * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
 * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
 * 随机给10名员工分配部门和工资
 * 通过multimap进行信息的插入  key(部门编号) value(员工)
 * 分部门显示员工信息
 *
 */

//使用常量定义分组
#define CEHUA 0
#define MEISHU 1
#define YANFA 2


//Worker类
class Worker {
public:
    string m_Name;
    int m_Salary;
};

//1.创建员工
void createWorker(vector<Worker> &v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        Worker worker;
        //拼接名字
        worker.m_Name = "Worker";
        worker.m_Name += nameSeed[i];
        //工资随机数
        worker.m_Salary = rand() % 10000 + 10000;     //10000~19999

        //将员工放入容器
        v.push_back(worker);
    }
}

//2.分组员工
void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator i = v.begin(); i != v.end(); ++i) {
        //产生随机部门编号
        int deptId = rand() % 3;  //0 1 2
        //将员工插入到分组中
        m.insert(make_pair(deptId, *i));
    }
}

//3.分组显示员工
void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "CEHUA" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    //统计策划人数
/*    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; ++pos, ++index) {
        cout << "name is " << pos->second.m_Name << ", salary is " << pos->second.m_Salary << endl;

    }*/

    for (; pos != m.end(); ++pos) {
        //查询到不是策划就终止执行
        if (pos->first != CEHUA) {
            break;
        }
        cout << "name is " << pos->second.m_Name << ", salary is " << pos->second.m_Salary << endl;
    }
    cout << "-----------------------------------" << endl;
    //美术
    cout << "MEISHU" << endl;
    pos = m.find(MEISHU);
    for (; pos != m.end(); ++pos) {
        //查询到不是策划就终止执行
        if (pos->first != MEISHU) {
            break;
        }
        cout << "name is " << pos->second.m_Name << ", salary is " << pos->second.m_Salary << endl;
    }
    cout << "-----------------------------------" << endl;
    //研发
    cout << "YANFA" << endl;
    pos = m.find(YANFA);
    for (; pos != m.end(); ++pos) {
        //查询到不是策划就终止执行
        if (pos->first != YANFA) {
            break;
        }
        cout << "name is " << pos->second.m_Name << ", salary is " << pos->second.m_Salary << endl;
    }
}

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));
    //1.创建员工
    vector<Worker> vWorker;
    createWorker(vWorker);

//    for (int i = 0; i < 10; ++i) {
//        cout << vWorker[i].m_Name << " " << vWorker[i].m_Salary << endl;
//    }

    //2.分组员工
    //分组map,key代表部分, Worker代表员工
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);

    //3.分组显示员工
    showWorkerByGroup(mWorker);


    return 0;
}
