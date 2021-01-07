#include <iostream>
#include "speechManager.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;


int main() {
    //随机数种子
    srand((unsigned int) time(NULL));
    //创建管理类对象
    SpeechManager speechManager;

    //测试选手创建
//    for (map<int, Speaker>::iterator i = speechManager.m_Speaker.begin(); i != speechManager.m_Speaker.end(); ++i) {
//        cout << i->first << " " << i->second.m_Name << " " << i->second.m_Score[0] << endl;
//    }


    int choice = 0;
    while (true) {
        speechManager.showMenu();
        cout << "Please input your choice" << endl;
        cin >> choice;
        switch (choice) {
            case 1 :    //1.start speech contest
                speechManager.startSpeech();
                break;
            case 2 :    //2.View past records
                speechManager.showRecord();
                break;
            case 3 :    //3.Clear contest records
                speechManager.clearRecord();
                break;
            case 0 :    //0.exit contest program
                speechManager.exitSystem();
                break;
            default:    //清屏
                system("cls");
                break;
        }

    }


    system("pause");

    return 0;
}
