#include "manager.h"
//���캯��
Manager::Manager(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}
//��ʾ������Ϣ
void Manager::showInfo() {
    cout << "ְ�����:" << this->m_Id << "\t";
    cout << "ְ������:" << this->m_Name << "\t";
    cout << "ְ����λ:" << this->getDepName() << "\t";
    cout << "��λְ��:����ϰ彻��������,�����·��������ͨԱ��" << endl;
}
//��ȡ��λ����
string Manager::getDepName() {
    return string("����");
}