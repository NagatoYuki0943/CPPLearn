#include <iostream>
#include "workerManager.h"
/**
 * 已知bug:再一次输入中可以输入相同id的人,因为一次输入多人只有全部输入完成之后才会存入堆区
 */

using namespace std;
int main() {

    //实例化管理者对象
    WorkerManager vm;

    int choice = 0;

    while (true) {
        //调用展示菜单函数
        vm.Show_Menu();

        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch (choice) {
            case 0:	//退出系统
                vm.ExitSystem();
                break;
            case 1:	//增加职工
                vm.Add_Emp();
                break;
            case 2:	//显示职工
                vm.Show_Emp();
                break;
            case 3:	//删除职工
                //{//测试
                //	int res = vm.IsExist(1);
                //	if (res != -1) {
                //		cout << "职工存在" << endl;
                //	}
                //	else {
                //		cout << "职工不存在" << endl;
                //	}
                //	break;
                //}
                vm.Del_Emp();
                break;
            case 4:	//修改职工
                vm.Mod_Emp();
                break;
            case 5:	//查找职工
                vm.Find_Emp();
                break;
            case 6:	//对职工进行排序
                vm.Sort_Emp();
                break;
            case 7:	//清空文档
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