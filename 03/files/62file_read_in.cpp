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
 * �鿴�ļ��Ƿ�Ϊ��
 * char ch;
 * ifs >> ch;  //��ȡһ���ַ�
 * if(ifs.eof()){  //�����ȡһ���ַ�,����ַ��ǽ�β,˵���ļ�Ϊ��  ifs.eof()
 * }
 */
void test01() {
    //1.����������
    //2.����������
    ifstream ifs;
    //3.���ļ����ж��Ƿ�򿪳ɹ�
    ifs.open("test.txt", ios::in);  //ios::in ���ļ� Ĭ�϶�ȡ�ļ���Ŀ¼��cmake-build-debug
    /// ifs.is_open() �жϴ򿪳ɹ�ʧ��
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    //��һ��
    cout << "1:" << endl;
    /*char buf0[1024]={0};
    ///ifs >> buf ��һֱ��ȡ,ֱ��Ϊ��ֹͣ
    while(ifs >> buf0){
        cout << buf0 << endl;
    }*/

    //�ڶ���
    cout << "2:" << endl;
    /*char buf1[1024]={0};
    ///ifs.getline(���λ��,��ȡ��Ŀ)
    while(ifs.getline(buf1,sizeof(buf1))){
        cout << buf1 << endl;
    }*/


    //������  �Ƽ�
    cout << "3:" << endl;
    string buf2;
    ///getline(����������,����λ��)
    /*while (getline(ifs,buf2)){
        cout << buf2 << endl;
    }*/

    //������:һ��һ���ַ���
    cout << "4:" << endl;
    char c;
    ///ifs.get() һ�ζ�һ���ַ�
    ///(c=ifs.get())!=EOF  DOF�ļ�β
    while ((c = ifs.get()) != EOF) {
        cout << c;
    }


    //5.�ر��ļ�
    ifs.close();

}

int main() {
    test01();
    system("pause");
    return 0;
}