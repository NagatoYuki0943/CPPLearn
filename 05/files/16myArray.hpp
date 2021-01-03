#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray {
public:
    //�вι���
    MyArray(int capacity) {
        //cout << "�вι���" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //��������
    MyArray(const MyArray &arr) {
        //cout << "��������" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //���
        this->pAddress = new T[this->m_Capacity];
        //����������
        for (int i = 0; i < this->m_Size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= ��ֹǳ��������
    MyArray &operator=(const MyArray &arr) {
        //cout << "operator=" << endl;
        //���ж�ԭ�������Ƿ�������,�����,���ͷ�,���ǲ��ÿ�ָ��
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //���
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        //��������
        return *this;
    }

    //��������
    ~MyArray() {
        if (this->pAddress != NULL) {
            cout << "��������" << endl;
            delete[] this->pAddress;
            this->pAddress == NULL;
            this->m_Size = 0;
            this->m_Capacity = 0;
        }
    }

    //β�巨
    void Push_Back(const T &val) {
        //�ж������Ƿ��Ѿ����ڴ�С
        if (this->m_Capacity == this->m_Size) {
            return;
        }
        //�嵽���һ��
        this->pAddress[this->m_Size] = val;
        this->m_Size++; //���ȼ�1
    }

    //βɾ��
    void Pop_Back() {
        //���û����ʲ������һ��Ԫ�ؼ���
        if (this->m_Size == 0) {
            return;
        }

        this->m_Size--;
    }

    //ͨ���±귽ʽ��������Ԫ�� arr[0]
    T &operator[](int index) {
        return this->pAddress[index];
    }

    //������������
    int getCapacity() {
        return this->m_Capacity;
    }

    //���������С
    int getSize() {
        return this->m_Size;
    }

private:
    T *pAddress;   //ָ��ָ�����ָ�����ʵ����
    //�������
    int m_Capacity;
    //Ŀǰ����
    int m_Size;
};