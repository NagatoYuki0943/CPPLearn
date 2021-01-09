

#ifndef INC_07_COMPUTERROOM_H
#define INC_07_COMPUTERROOM_H

#pragma once

#include <iostream>

using namespace std;

//机房类
class ComputerRoom {
public:
    //默认构造函数
    ComputerRoom();

    //构造函数
    ComputerRoom(int id, int maxNum);


    int m_ComId;    //机房id号

    int m_MaxNum;   //机房最大容量
};

#endif //INC_07_COMPUTERROOM_H
