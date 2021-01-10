//功能描述：显示预约记录时，需要从文件中获取到所有记录，用来显示，创建预约的类来管理记录以及更新

#ifndef INC_07_ORDERFILE_H
#define INC_07_ORDERFILE_H

#pragma once

using namespace std;

#include <iostream>
#include <map>
#include <fstream>
#include "identity.h"
#include "globalFile.h"

class OrderFile {
public:
    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    //第一层map是记录的条数,第二层map是里面的键值对,如日期,时间段等
    //date : 1 interval : 1 stuId : 1 stuName : zhangsan roomId : 1 status : 1
    //date : 5 interval : 2 stuId : 2 stuName : lisi roomId : 3 status : 1
    map<int, map<string, string>> m_OrderData;

    //预约记录条数
    int m_Size;
};


#endif //INC_07_ORDERFILE_H
