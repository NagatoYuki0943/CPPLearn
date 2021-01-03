#include <iostream>
#include <ctime>

using namespace std;
//3个老师,每名老师带5名学生,打印老师和学生的信息
struct student {
    string sName;
    int score;
};

struct teacher {
    //姓名
    string tName;
    //5名学生的数组
    struct student sArray[5];
};

//给老师和学生赋值的函数
void allocateSpace(struct teacher tArray[], int len) {   //也可以使用指针传递
    //给老师赋值
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++) {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i]; //加等于nameSeed中字符串的位置的字母

        //给每名学生赋值
        for (int j = 0; j < 5; j++) {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];  //学生后面跟上字母

            //随机分数
            int random = rand() % 61 + 40;  //(0-60)+40
            tArray[i].sArray[j].score = random;
        }
    }
}

//打印所有信息
void printInfo(struct teacher tArray[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "老师姓名:" << tArray[i].tName << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t学生姓名:" << tArray[i].sArray[j].sName << " 分数:" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));   //要使用#include <ctime>

    //创建三名老师的数组
    struct teacher tArray[3];

    //通过函数给3名老师的信息赋值,并给老师带的学生信息赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);

    //数组名就是地址,直接放入函数就可以影响实际数组参数
    allocateSpace(tArray, len);

    //打印所有信息
    printInfo(tArray, len);
    return 0;
}