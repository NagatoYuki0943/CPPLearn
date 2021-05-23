#include <iostream>
#include <fstream>
using namespace std;
/**
 * ע��:clionĬ�϶�д�ļ���Ŀ¼��cmake-build-debugĿ¼
 */
/**
 * ��������ʱ���������ݶ�������ʱ����,����һ�����н��������ͷ�
 * ͨ���ļ����Խ����ݳ־û�
 * C++���ļ�������Ҫ����ͷ�ļ�<fstream>
 *
 * �ļ����ͷ�Ϊ����:
 *      1.�ı��ļ�    -�ļ����ı���ASCII����ʽ�洢�ڼ������
 *      2.�������ļ�   -�ļ����ı��Ķ�������ʽ�洢�ڼ������,�û�һ�벻��ֱ�Ӷ�������
 * �����ļ���������:
 *      1.ofstream:д����  output
 *      2.ifstream:������  input
 *      3.fstream:��д����  file
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

void test01(){
    //1.����ͷ�ļ�     #include <fstream>
    //2.����������     ofstream ofs;
    ofstream ofs;
    //3.ָ���򿪷�ʽ
    ///�ļ�·��Ĭ����exeִ��·��,vs�к�cpp��ͬһ·��
    ofs.open("test.txt",ios::out);  //outд,in��
    //4.���ļ���д����
    ofs << "����:����" << endl; //endl ����
    ofs << "�Ա�:��" << endl;
    ofs << "����:18" << endl;
    ofs.close();
}
int main() {
    test01();
    system("pause");
    return 0;
}