#include "orderFile.h"

//构造函数
OrderFile::OrderFile() {
    //清空
    m_OrderData.clear();

    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string date;        //日期
    string interval;    //时间段
    string stuId;       //学生编号
    string stuName;     //学生姓名
    string roomId;      //机房编号
    string status;      //预约状态

    this->m_Size = 0;   //记录预约个数

    //ifs是按照空格进行分割的,所以拿出来的单个数据是date : 1  interval : 1 这样的
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
        //测试
        cout << date << " | " << interval << " | " << stuId << " | " << stuName << " | " << roomId << " | " << status
             << endl;

        string key;
        string value;
        map<string, string> m;

        //date
        int pos = date.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //interval
        pos = interval.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //stuId
        pos = stuId.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //stuName
        pos = stuName.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //roomId
        pos = roomId.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //status
        pos = status.find(":");
        //找不到返回 -1
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //插入二维map
        this->m_OrderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();

    //测试代码
    //m_OrderData 的first是数字key,second是单个的map
    for (map<int, map<string, string>>::iterator i = this->m_OrderData.begin(); i != this->m_OrderData.end(); ++i) {
        cout << "key = " << i->first << " value = " << endl;
        //i->second是一个map,可以使用 begen和end
        for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); ++j) {
            cout << j->first << " " << j->second << " | ";
        }
        cout << endl;
    }


}