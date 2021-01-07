#include "speechManager.h"


//构造函数
SpeechManager::SpeechManager() {
    //调用初始化容器函数
    this->initSpeech();

    //创建12名选手
    this->createSpeaker();

    //加载往届记录
    this->loadRecord();
}


//析构函数
SpeechManager::~SpeechManager() {

}


//显示菜单
void SpeechManager::showMenu() {
    cout << "***************************************************************" << endl;
    cout << "*************  welcome come to the speech contest  ************" << endl;
    cout << "*************        1.start speech contest        ************" << endl;
    cout << "*************        2.View past records           ************" << endl;
    cout << "*************        3.Clear contest records       ************" << endl;
    cout << "*************        0.exit contest program        ************" << endl;
    cout << "***************************************************************" << endl;
    cout << endl;
}


//退出系统
void SpeechManager::exitSystem() {
    cout << "See you next time" << endl;
    system("pause");
    exit(0);
}


//初始化容器和属性
void SpeechManager::initSpeech() {
    //初始化第一轮容器
    this->v1.clear();
    //初始化第二轮容器
    this->v2.clear();
    //初始化冠军容器
    this->vVictory.clear();
    //初始化存放编号和人员名字的容器
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_Index = 1;
    //初始化记录容器
    this->m_Record.clear();
}


//创建12选手
void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "Speaker";
        //拼接名字
        name += nameSeed[i];

        //创建选手对象
        Speaker sp;
        sp.m_Name = name;

        //输入两轮的分数
        for (int j = 0; j < 2; ++j) {
            sp.m_Score[j] = 0;
        }

        //创建选手编号,并放入v1容器中
        this->v1.push_back(i + 10001);

        //选手编号和选手放入到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}


//开始比赛,比赛流程控制
void SpeechManager::startSpeech() {
    //第一轮比赛
    //1、抽签
    this->speechDraw();

    //2、比赛
    this->speechContest();

    //3、显示晋级结果
    this->showScore();

    //第二轮比赛
    this->m_Index++;
    //1、抽签
    this->speechDraw();

    //2、比赛
    this->speechContest();

    //3、显示最终结果
    this->showScore();

    //4、保存分数
    this->saveRecord();

    //重置比赛
    this->initSpeech();

    //创建12名选手
    this->createSpeaker();

    //加载往届记录
    this->loadRecord();
}


//抽签
void SpeechManager::speechDraw() {
    cout << "----------This is the " << this->m_Index << " round,Drawing!!!---------" << endl;
    cout << "----------------The result of the draw is as follows:------------------" << endl;
    if (this->m_Index == 1) {
        //第一轮
        //随机打乱
        random_shuffle(v1.begin(), v1.end());
        //输出,和下面最终目的一样
        for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;

    } else {
        //第二轮
        //随机打乱
        random_shuffle(v2.begin(), v2.end());
        //输出,和上面结果一样
        for (int i = 0; i < v2.size(); ++i) {
            cout << v2[i] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------" << endl;
    system("pause");
}


//比赛
void SpeechManager::speechContest() {
    cout << "-----------This is the " << this->m_Index << " round contest!!!----------" << endl;

    //准备临时容器,存放小组成绩(6人一组)   key是得分,value是得分人的编号
    multimap<double, int, greater<double>> groupScore;  //第三个参数是从大到小排列
    //统计人员个数,6人一组
    int number = 0;


    vector<int> v_Src;  //比赛选手容器
    if (this->m_Index == 1) {
        //第1轮
        v_Src = v1;
    } else {
        //第2轮
        v_Src = v2;
    }

    //遍历所有选手进行比赛
    for (vector<int>::iterator i = v_Src.begin(); i != v_Src.end(); ++i) {
        number++;
        //评委打分
        deque<double> d;
        for (int j = 0; j < 10; ++j) {
            double score = (rand() % 401 + 600) / 10.f;   //600~1000 /10 == 60~100   10.f代表是小数
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        //排序
        sort(d.begin(), d.end());    //降序

        d.pop_front();  //去除最低分
        d.pop_back();   //去除最高分

        //累加分数
        double sum = accumulate(d.begin(), d.end(), 0.00f);

        //平均分
        double avg = sum / (double) d.size();

        //打印平均分
        //cout << "Number : " << *i << " Speaker : " << this->m_Speaker[*i].m_Name << " Score : " << avg << endl;
        //cout << endl;

        //将平均分放入容器中
        // i是从v1或者v2中取出的编号,就是选手的编号, m_Index = 1/2 , 减一就是数组中的位置
        this->m_Speaker[*i].m_Score[this->m_Index - 1] = avg;

        //将打分的数据放入临时的小组容器中
        //key是得分,value是得分人的编号
        groupScore.insert(make_pair(avg, *i));

        //6人一组,进行分组
        if (number % 6 == 0) {
            cout << "The " << number / 6 << " group is ranked as follows:" << endl;
            for (multimap<double, int, greater<double>>::iterator j = groupScore.begin(); j != groupScore.end(); ++j) {
                cout << "Number : " << j->second << " Name : " << this->m_Speaker[j->second].m_Name
                     << " Score : " << m_Speaker[j->second].m_Score[this->m_Index - 1] << endl;
            }

            //取出前三名放入其中
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator j = groupScore.begin();
                 j != groupScore.end() && count < 3; ++j, ++count) {
                if (this->m_Index == 1) {
                    // *j 的值是编号,取出来,放进v2
                    v2.push_back((*j).second);
                } else {
                    vVictory.push_back((*j).second);
                }
            }

            //清空小组容器
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "------------The " << this->m_Index << " contest has finished-------------" << endl;
    cout << endl;
    system("pause");
}


//显示比赛结果
void SpeechManager::showScore() {
    cout << "---The " << this->m_Index << " group of advanced players are as follows--" << endl;
    vector<int> v;

    if (this->m_Index == 1) {
        //第一轮比完了,指向第二轮
        v = v2;
    } else {
        //第二轮比完了,指向结果
        v = vVictory;
    }

    cout << v.size() << endl; //6

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << "Number : " << *i << " Speaker : " << this->m_Speaker[*i].m_Name << " Score : "
             << this->m_Speaker[*i].m_Score[this->m_Index - 1] << endl;
    }

    system("pause");
    //清屏
    system("cls");
    this->showMenu();
}


//保存记录
void SpeechManager::saveRecord() {
    //文件输入输出流
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); //out写文件,app(append)附加

    //将所有冠军文件保存
    for (vector<int>::iterator i = vVictory.begin(); i != vVictory.end(); ++i) {
        ofs << *i << "," << m_Speaker[*i].m_Score[1] << ",";
    }
    ofs << endl;

    //关闭文件
    ofs.close();

    cout << "The records has been saved" << endl;

    //实时更新
    this->fileIsEmpty = false;

    //清屏
    system("cls");
}


//读取记录
void SpeechManager::loadRecord() {
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

    //文件不存在
    if (!ifs.is_open()) {
        //测试
        //cout << "File is not exist!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //直接读到文件尾,文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //测试
        //cout << "File is empty!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;
    //将取出的单个字符放回去
    ifs.putback(ch);

    //保存提取出来字符串
    string data;

    //第0届
    int index = 0;


    while (ifs >> data) {
        //cout << data << endl;
        //10002,86.675,10009,81.3,10007,78.55,  有数据,成功
        //File is not exist!    没有文件
        //File is empty!        文件为空

        //存放6个string字符串
        vector<string> v;


        //查到逗号的位置,默认没查到
        int pos = -1;
        //查询起始位置
        int start = 0;

        while (true) {
            pos = data.find(",", start);

            if (pos == -1) {
                //没有找到的情况,或者找到最后
                break;
            }
            //分割 参数1 起始位置，参数2 截取长度
            string temp = data.substr(start, pos - start);
            //cout << temp << " ";    //10002 86.675 10009 81.3 10007 78.55 *

            //将提取出来的字符串放入v
            v.push_back(temp);

            //修改start位置,逗号后面
            start = pos + 1;
        }

        //index是第几届,v代表第几届的成绩
        this->m_Record.insert(make_pair(index, v));
        index++;
    }

    ifs.close();


    //测试,查看m_Record中的数据
//    for (map<int, vector<string>>::iterator i = this->m_Record.begin(); i != this->m_Record.end(); ++i) {
//        //second是一个vector,可以通过下标获取数据
//        cout << i->first << " champion number : " << i->second[0] << " champion score : " << i->second[1] << endl;
//        //0 champion number : 10002 champion score : 86.675
//        //1 champion number : 10002 champion score : 86.675
//    }
}


//显示往届得分
void SpeechManager::showRecord() {
/*    for (int i = 0; i < m_Record.size(); ++i) {
        cout << m_Record[i][0] << " ";
        cout << m_Record[i][1] << " ";
        cout << m_Record[i][2] << " ";
        cout << m_Record[i][3] << " ";
        cout << m_Record[i][4] << " ";
        cout << m_Record[i][5] << " ";
    }*/
    //10002 86.675 10009 81.3 10007 78.55 10002 86.675 10009 81.3 10007 78.55
    if(fileIsEmpty){
        cout << "File is empty or file is not exist"  << endl;
    } else{

        for (int i = 0; i < m_Record.size(); ++i) {
            //m_Record
            cout << "The " << i + 1 << " advantage :" << endl;
            cout << "  champion number     : " << this->m_Record[i][0] << "    champion score     : " << this->m_Record[i][1]
                 << endl;
            cout << "  second place number : " << this->m_Record[i][2] << "    second place score : " << this->m_Record[i][3]
                 << endl;
            cout << "  third place number  : " << this->m_Record[i][4] << "    third place score  : " << this->m_Record[i][5]
                 << endl;
        }
    }


    //The 1 advantage :
    //  champion number     : 10002    champion score     : 86.675
    //  second place number : 10009    second place score : 81.3
    //  third place number  : 10007    third place score  : 78.55
    //The 2 advantage :
    //  champion number     : 10002    champion score     : 86.675
    //  second place number : 10009    second place score : 81.3
    //  third place number  : 10007    third place score  : 78.55

    system("pause");
    system("cls");
}


//清空记录
void SpeechManager::clearRecord(){
    cout << "Confirm to empty?" << endl;
    cout << "1,confirm" << endl;
    cout << "else,close" << endl;
    int select = 0;
    cin >> select;
    if(select == 1){
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs("speech.csv",ios::trunc);
        ofs.close();

        //重新初始化

        //调用初始化容器函数
        this->initSpeech();

        //创建12名选手,重新生成
        this->createSpeaker();

        //加载往届记录,清空记录
        this->loadRecord();
    }
    system("pause");
    system("cls");
}