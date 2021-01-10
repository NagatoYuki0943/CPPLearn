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

    //一次一行
    //ifs是按照空格进行分割的,所以拿出来的单个数据是date : 1  interval : 1 这样的
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
        //测试
        //cout << date << "  " << interval << "  " << stuId << "  " << stuName << "  " << roomId << "  " << status
        //     << endl;
        //date:5  interval:2  stuId:1  stuName:zhangsan  roomId:3  status:1
        //date:2  interval:2  stuId:2  stuName:lisi  roomId:2  status:1

        string key;
        string value;
        map<string, string> m;

        //date:5
        //查找 : ,返回int位置,位置从0开始数
        int pos = date.find(":");   //pos = 4
        //找不到返回 -1
        if (pos != -1) {
            key = date.substr(0, pos);  //从0开始截取4个
            value = date.substr(pos + 1, date.size() - pos - 1);    //从4 + 1开始取, date.size() = 6, 6 - 4 - 1 = 1
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
        //m_Size是下标,m是map
        this->m_OrderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();

    //测试一维map代码
    //m_OrderData 的first是数字key,second是单个的map
//    for (map<int, map<string, string>>::iterator i = this->m_OrderData.begin(); i != this->m_OrderData.end(); ++i) {
//        cout << "key = " << i->first << " value = " << endl;
//        //i->second是一个map,可以使用 begen和end
//        for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); ++j) {
//            cout << j->first << " " << j->second << " | ";
//        }
//        cout << endl;
//    }
    //key = 0 value =
    //date 5 | interval 2 | roomId 3 | status 1 | stuId 1 | stuName zhangsan |
    //key = 1 value =
    //date 2 | interval 2 | roomId 2 | status 1 | stuId 2 | stuName lisi |


}


//更新预约记录
void OrderFile::updateOrder() {
    //没有预约
    if (this->m_Size == 0) {
        return;
    }

    //打开方式是输出或者截取
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    //把m_OrderData中的数据写入原来的文件
    for (int i = 0; i < m_Size; ++i) {
        ofs << "date:" << this->m_OrderData[i]["date"] << " ";
        ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_OrderData[i]["status"] << endl;
    }
    ofs.close();

}