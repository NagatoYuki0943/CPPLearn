#include <iostream>
using namespace std;
int main() {



    //用于接收用户的选择
    int select = 0;
    while (true){
        cout << "======================  Welcome to the computer room reservation system  ====================="
             << endl;
        cout << endl << "Please input your identity : " << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.Student            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.Teacher            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.Administrator      |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.Exit               |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "Please input your choice : ";

        cin >> select;

        switch (select) {
            case 1:     //1.Student
                break;
            case 2:     //2.Teacher
                break;
            case 3:     //3.Administrator
                break;
            case 0:     //0.Exit
                cout << "See you next time" << endl;
                system("pause");
                exit(0);   //exit(0) 和 return 0 ;效果相同,不过在方法中不能使用return 0,只能使用exit(0);
                return 0;
            default:
                cout << "Input error,please input again" << endl;
                system("pause");
                system("cls");
                break;
        }
    }


    system("pause");

    return 0;
}
