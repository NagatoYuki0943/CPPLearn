#include "boss.h"
//���캯��
Boss::Boss(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}
//��ʾ������Ϣ
void Boss::showInfo() {
    cout << "ְ�����:" << this->m_Id << "\t";
    cout << "ְ������:" << this->m_Name << "\t";
    cout << "ְ����λ:" << this->getDepName() << "\t";
    cout << "��λְ��:����˾��������" << endl;
}
//��ȡ��λ����
string Boss::getDepName() {
    return string("�ϰ�");
}