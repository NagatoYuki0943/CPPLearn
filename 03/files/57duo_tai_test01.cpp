#include <iostream>

using namespace std;

/**
 * ��������:
 *      ֻ����Ʒ�Ĵ�������Ϊ:��ˮ-����-���뱭��-���븨��
 *      ���ö�̬����ʵ�ֱ�����,�ṩ����������Ʒ����,�ṩ�����������ȺȲ�Ҷ
 */
class AbstractDrinking {
public:
    //��ˮ
    virtual void Boil() = 0;

    //����
    virtual void Brew() = 0;

    //���뱭��
    virtual void PourInCup() = 0;

    //���븨��
    virtual void AddSomething() = 0;

    //ֻ����Ʒ
    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        AddSomething();
    }
};

//����
class Coffee : public AbstractDrinking {
    //��ˮ
    void Boil() {
        cout << "���Ȫˮ" << endl;
    }

    //����
    void Brew() {
        cout << "���ݿ���" << endl;
    }

    //���뱭��
    void PourInCup() {
        cout << "���뱭��" << endl;
    }

    //���븨��
    void AddSomething() {
        cout << "�����Ǻ�ţ��" << endl;
    }
};

//��Ҷ
class Tea : public AbstractDrinking {
    //��ˮ
    // �µ�д������ʹ�� override �ؼ���
    void Boil() override {
        cout << "�󴿾�ˮ" << endl;
    }

    //����
    void Brew() override {
        cout << "���ݲ�Ҷ" << endl;
    }

    //���뱭��
    void PourInCup() override {
        cout << "���뱭��" << endl;
    }

    //���븨��
    void AddSomething() override {
        cout << "��������" << endl;
    }
};

//��������
void doWork(AbstractDrinking &drinking) {
    drinking.makeDrink();
}

void test01() {
    //��������
    Coffee coffee;
    doWork(coffee);
    cout << "-------------------" << endl;
    //������Ҷ
    Tea tea;
    doWork(tea);
}

int main() {
    test01();
    system("pause");
    return 0;
}