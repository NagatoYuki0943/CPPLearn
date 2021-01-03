#include <iostream>
#include <string>
#include "16myArray.hpp"

using namespace std;

/**
 * ��������:ʵ��һ��ͨ�õ�������,Ҫ������:
 *  1.���Զ������������ͺ��Զ����������͵����ݽ��д洢
 *  2.�������е����ݴ洢������
 *  3.���캯���п��Դ������������
 *  4.�ṩ��Ӧ�Ŀ������캯���Լ� operator= ��ֹ��������
 *  5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
 *  6.����ͨ���±�ķ�ʽ���������е�Ԫ��
 *  7.���Ի�ȡ�����е�ǰԪ�ظ���������
 */
//�����ӡ
void printIntArray(MyArray<int> array) {
    for (int i = 0; i < array.getSize(); ++i) {
        cout << array[i] << endl;
    }
}

void test01() {
    MyArray<int> arr1(5);   //�вι���  ��������
    MyArray<int> arr2(arr1);    //��������  ��������
    MyArray<int> arr3(100); //�вι���  ��������
    arr3 = arr1;    //operator=
}

void test02() {
    MyArray<int> arr1(5);
    for (int i = 0; i < 5; ++i) {
        //����β�巨�������в���Ԫ��
        arr1.Push_Back(i + 10);
    }

    //��ӡ����
    cout << "arr1:" << endl;
    printIntArray(arr1);    //10 11 12 13 14

    //��ȡ����
    cout << "arr1.Capacity = " << arr1.getCapacity() << endl;   // 5
    //��ȡ����
    cout << "arr1.Size = " << arr1.getSize() << endl;           // 5

    MyArray<int> arr2(arr1);
    cout << "arr2:" << endl;
    printIntArray(arr1);    //10 11 12 13 14

    //βɾ
    arr2.Pop_Back();
    //��ȡ����
    cout << "arr2.Capacity = " << arr2.getCapacity() << endl;   // 5    ��������
    //��ȡ����
    cout << "arr2.Size = " << arr2.getSize() << endl;           // 4    ����-1
}

//�����Զ������������
class Person {
public:
    //���˹��캯����ʧ��,�ڶ������ݴ�����ʱ����Ҫ����,����Ҫ����һ���յĹ��캯��
    Person(){}
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

//��ӡPerson
void printPersonArray(MyArray<Person> &arr) {
    cout << "printPersonArray" << endl;
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << "name : " << arr[i].m_Name << " age:" << arr[i].m_Age << endl;
    }
}

void test03() {
    MyArray<Person> arr(10);
    Person p1("�����",999);
    Person p2("����",10);
    Person p3("��ɮ",20);
    Person p4("��˽�",50);
    Person p5("ʸ���ݿ�",16);


    //�����ݲ��뵽������
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    printPersonArray(arr);

    //��ȡ����
    cout << "arrPerson.Capacity = " << arr.getCapacity() << endl;   // 5
    //��ȡ����
    cout << "arrPerson.Size = " << arr.getSize() << endl;
}

int main() {
    //test01();
    //test02();
    test03();
    return 0;
}
