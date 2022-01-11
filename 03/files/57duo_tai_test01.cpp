#include <iostream>

using namespace std;

/**
 * 案例描述:
 *      只做饮品的大致流程为:煮水-冲泡-倒入杯中-加入辅料
 *      利用多态技术实现本案例,提供抽象制作饮品基类,提供子类制作咖啡喝茶叶
 */
class AbstractDrinking {
public:
    //煮水
    virtual void Boil() = 0;

    //冲泡
    virtual void Brew() = 0;

    //倒入杯中
    virtual void PourInCup() = 0;

    //加入辅料
    virtual void AddSomething() = 0;

    //只做饮品
    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        AddSomething();
    }
};

//咖啡
class Coffee : public AbstractDrinking {
    //煮水
    void Boil() {
        cout << "煮矿泉水" << endl;
    }

    //冲泡
    void Brew() {
        cout << "冲泡咖啡" << endl;
    }

    //倒入杯中
    void PourInCup() {
        cout << "倒入杯中" << endl;
    }

    //加入辅料
    void AddSomething() {
        cout << "加入糖和牛奶" << endl;
    }
};

//茶叶
class Tea : public AbstractDrinking {
    //煮水
    // 新的写法可以使用 override 关键字
    void Boil() override {
        cout << "煮纯净水" << endl;
    }

    //冲泡
    void Brew() override {
        cout << "冲泡茶叶" << endl;
    }

    //倒入杯中
    void PourInCup() override {
        cout << "倒入杯中" << endl;
    }

    //加入辅料
    void AddSomething() override {
        cout << "加入柠檬" << endl;
    }
};

//工作函数
void doWork(AbstractDrinking &drinking) {
    drinking.makeDrink();
}

void test01() {
    //制作咖啡
    Coffee coffee;
    doWork(coffee);
    cout << "-------------------" << endl;
    //制作茶叶
    Tea tea;
    doWork(tea);
}

int main() {
    test01();
    system("pause");
    return 0;
}