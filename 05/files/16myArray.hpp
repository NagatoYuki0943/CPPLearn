#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
public:
    //有参构造
    MyArray(int capacity) {
        //cout << "有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //拷贝构造
    MyArray(const MyArray &arr) {
        //cout << "拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //深拷贝
        this->pAddress = new T[this->m_Capacity];
        //并拷贝数据
        for (int i = 0; i < this->m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝问题
    MyArray &operator=(const MyArray &arr) {
        //cout << "operator=" << endl;
        //先判断原来堆区是否有数据,如果有,先释放,但是不置空指针
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        //返回自身
        return *this;
    }

    //析构代码
    ~MyArray() {
        if (this->pAddress != NULL) {
            cout << "析构函数" << endl;
            delete[] this->pAddress;
            this->pAddress == NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }
    }

    //尾插法
    void Push_Back(const T &val) {
        //判断容量是否已经等于大小
        if (this->m_Capacity == this->m_Size) {
            return;
        }
        //插到最后一个
        this->pAddress[this->m_Size] = val;
        this->m_Size++; //长度加1
    }

    //尾删法
    void Pop_Back() {
        //让用户访问不到最后一个元素即可
        if (this->m_Size == 0) {
            return;
        }

        this->m_Size--;
    }

    //通过下标方式访问数组元素 arr[0]
    T &operator[](int index) {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity() {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize() {
        return this->m_Size;
    }

private:
    T *pAddress;   //指针指向堆区指向的真实数组
    //最大容量
    int m_Capacity;
    //目前长度
    int m_Size;
};