#include <iostream>
#include "workerManager.h"
/**
 * ��֪bug:��һ�������п���������ͬid����,��Ϊһ���������ֻ��ȫ���������֮��Ż�������
 */

using namespace std;
int main() {

    //ʵ���������߶���
    WorkerManager vm;

    int choice = 0;

    while (true) {
        //����չʾ�˵�����
        vm.Show_Menu();

        cout << "����������ѡ��" << endl;
        cin >> choice;

        switch (choice) {
            case 0:	//�˳�ϵͳ
                vm.ExitSystem();
                break;
            case 1:	//����ְ��
                vm.Add_Emp();
                break;
            case 2:	//��ʾְ��
                vm.Show_Emp();
                break;
            case 3:	//ɾ��ְ��
                //{//����
                //	int res = vm.IsExist(1);
                //	if (res != -1) {
                //		cout << "ְ������" << endl;
                //	}
                //	else {
                //		cout << "ְ��������" << endl;
                //	}
                //	break;
                //}
                vm.Del_Emp();
                break;
            case 4:	//�޸�ְ��
                vm.Mod_Emp();
                break;
            case 5:	//����ְ��
                vm.Find_Emp();
                break;
            case 6:	//��ְ����������
                vm.Sort_Emp();
                break;
            case 7:	//����ĵ�
                vm.Clean_File();
                break;
            default :
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}