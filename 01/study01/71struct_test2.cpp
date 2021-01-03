#include <iostream>

using namespace std;
/**
 * 设计一个英雄的结构体,包括成员姓名,年龄,性别;创建结构体数组,数组中存放5名英雄,
 * 通过冒泡排序的算法,将数组中的英雄按照年龄进行升序排序,打印最终排序的结果
 */
//1.创建英雄结构体
struct Hero {
    string name;
    int age;
    string sex;
};

//3.冒泡排序,按照年龄升序排列
void bubbleSoft(struct Hero heroArray[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (heroArray[j].age > heroArray[j + 1].age) {
                struct Hero tmp;
                tmp = heroArray[j];
                heroArray[j] = heroArray[j + 1];
                heroArray[j + 1] = tmp;
            }
        }
    }
}

//4.打印排序后输出
void printHero(struct Hero heroArray[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "姓名:" << heroArray[i].name << " 年龄:" << heroArray[i].age << " 性别:" << heroArray[i].sex << endl;
    }
}

int main() {
    //2.创建数组存放5名英雄
    struct Hero heroArray[5] = {
            {"刘备", 23, "男"},
            {"关羽", 22, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "女"}
    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);

    //测试
    cout << "排序前输出:" << endl;
    for (int i = 0; i < len; i++) {
        cout << "姓名:" << heroArray[i].name << " 年龄:" << heroArray[i].age << " 性别:" << heroArray[i].sex << endl;
    }

    //排序
    bubbleSoft(heroArray, len);
    //输出
    cout << "排序后输出:" << endl;
    printHero(heroArray, len);
    return 0;
}