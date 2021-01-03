#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

/**
 * 案例描述
 *  有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
 * 实现步骤
 *  1. 创建五名选手，放到vector中
 *  2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
 *  3. sort算法对deque容器中分数排序，去除最高和最低分
 *  4. deque容器遍历一遍，累加总分
 *  5. 获取平均分
 */

//人类
class Person {
public:
    Person(string name, int score) : m_Name(name), m_Score(score) {
    }

    string m_Name;  //姓名
    int m_Score;    //平均分
};

//创建选手
void createaPerson(vector<Person> &v) {
    string nameSeed = "ANCDE";
    for (int i = 0; i < 5; ++i) {
        string name = "player ";
        name += nameSeed[i];
        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

//设置分数
void setScore(vector<Person> &v) {
    for (int i = 0; i < v.size(); ++i) {
        //奖评委的分数放入deque容器中
        deque<int> d;
        for (int j = 0; j < 10; ++j) {
            int score = rand() % 41 + 60; //60 - 100  随机出0 - 40,在加上 + 60
            d.push_back(score); //放入容器中
        }
        sort(d.begin(), d.end());

        //去除最高分和最低分
        d.pop_front();
        d.pop_back();

        //取平均分
        int sum = 0;
        for (deque<int>::iterator k = d.begin(); k != d.end(); ++k) {
            sum += *k;
        }
        int avg = sum / d.size();

        v[i].m_Score = avg;

        //测试
        //cout << v[i].m_Name << "-" << v[i].m_Score << "  "; //player A-78  player N-82  player C-74  player D-80  player E-77
    }

}

//打印分数
void printScore(vector<Person> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << "name : " << v[i].m_Name << " score : " << v[i].m_Score << endl;
    }
}


int main() {
    //随机数种子
    srand((unsigned int) time(NULL));

    //1.创建5名选手
    vector<Person> v;
    createaPerson(v);

    //测试
//    for (vector<Person>::iterator i = v.begin(); i != v.end(); ++i) {
//        cout << i->m_Name << "-" << i->m_Score << " | ";    //player A-0 | player N-0 | player C-0 | player D-0 | player E-0 |
//    }
    cout << endl;

    //2.给5名选手打分
    setScore(v);

    //3.显示最后得分
    printScore(v);
    //name : player A score : 78
    //name : player N score : 82
    //name : player C score : 74
    //name : player D score : 80
    //name : player E score : 77

    return 0;
}
