#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/**
 * ע��:clionĬ�϶�д�ļ���Ŀ¼��cmake-build-debugĿ¼
 */
/**
 * д�ļ�����
 *  1.����ͷ�ļ�     #include <fstream>
 *  2.����������     ofstream ofs;
 *  3.�򿪷�ʽ      ofs.open("�ļ�·��",�򿪷�ʽ);
 *  4.д����        ofs << "д�������"
 *  5.�ر��ļ�      ofs.close();
 */
/**
 * �ļ��򿪷�ʽ      ����
 * ios::out        Ϊд�ļ������ļ�
 * ios::in         Ϊ���ļ������ļ�
 * ios::ate        ��ʼλ��:�ļ�β
 * ios::app        ׷�ӷ�ʽд�ļ�
 * ios::trunc      ����ļ�������ɾ��,�ٴ���
 * ios::binary     �����Ʒ�ʽ
 * ע��:�ļ��򿪷�ʽ�������ʹ��,���� | ������
 * ����:�ö����Ʒ�ʽд�ļ� ios::binary | ios::out
 */
/**
 * �����ƶ��ļ�
 * �򿪷�ʽ: ios::binary
 * �����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
 * ����ԭ�� istream & read(char * buffer, int len);
 * ��������:�ַ�ָ��bufferָ���ڴ��е�һ�δ洢�ռ�,len�Ƕ����ֽ���
 */
class Person {
public:
    char m_Name[64];
    int m_Age;
};

void test01() {
    //1.����ͷ�ļ�
    //2.����������
    ifstream ifs;
    //3.���ļ�,�ж��ļ��Ƿ�򿪳ɹ�
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.���ļ�
    Person p;
    ifs.read((char *) &p, sizeof(Person));
    cout << "����:" << p.m_Name << endl;   //��������,vs���Կ���
    cout << "����:" << p.m_Age << endl;
    //5.�ر��ļ�
    ifs.close();
}


int main() {
    test01();
    system("pause");
    return 0;
}