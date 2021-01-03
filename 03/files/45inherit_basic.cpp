#include <iostream>

using namespace std;
/**
 * �̳�
 * �﷨: class ���� : �̳з�ʽ ����
 *  ����(����):
 *      class BasePage{}
 *  ����(������):
 *      class Java : public BasePage{}
 *      class Python : public BasePage{}
 *      class CPP : public BasePage{}
 *   publicָ���Ǽ̳з�ʽ
 */
/*//��ͨʵ��ҳ��
//JAVAҳ��
class Java{
public:
    void header(){
        cout << "��ҳ,������,��¼,ע��...(����ͷ��)" << endl;
    }
    void footer(){
        cout << "��������,��������,վ�ڵ�ͼ...(�����ײ�)" << endl;
    }
    void left(){
        cout << "Java,Python,C++...(�����б�)" << endl;
    }
    void content(){
        cout << "Javaѧ����Ƶ" << endl;
    }
};
//Pythonҳ��
class Python{
public:
    void header(){
        cout << "��ҳ,������,��¼,ע��...(����ͷ��)" << endl;
    }
    void footer(){
        cout << "��������,��������,վ�ڵ�ͼ...(�����ײ�)" << endl;
    }
    void left(){
        cout << "Java,Python,C++...(�����б�)" << endl;
    }
    void content(){
        cout << "Pythonѧ����Ƶ" << endl;
    }
};
//C++
class CPP{
public:
    void header(){
        cout << "��ҳ,������,��¼,ע��...(����ͷ��)" << endl;
    }
    void footer(){
        cout << "��������,��������,վ�ڵ�ͼ...(�����ײ�)" << endl;
    }
    void left(){
        cout << "Java,Python,C++...(�����б�)" << endl;
    }
    void content(){
        cout << "C++ѧ����Ƶ" << endl;
    }
};*/
//�̳�ʵ��
class BasePage {
public:
    void header() {
        cout << "��ҳ,������,��¼,ע��...(����ͷ��)" << endl;
    }

    void footer() {
        cout << "��������,��������,վ�ڵ�ͼ...(�����ײ�)" << endl;
    }

    void left() {
        cout << "Java,Python,C++...(�����б�)" << endl;
    }
};

///�﷨:      class ���� : �̳з�ʽ ����
//Javaҳ��
class Java : public BasePage {
public:
    void content() {
        cout << "Javaѧ����Ƶ" << endl;
    }
};

class Python : public BasePage {
public:
    void content() {
        cout << "Pythonѧ����Ƶ" << endl;
    }
};

class CPP : public BasePage {
public:
    void content() {
        cout << "C++ѧ����Ƶ" << endl;
    }
};

void test01() {
    Java ja;
    cout << "Java������Ƶҳ������" << endl;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout << "------------------" << endl;
    Python py;
    cout << "Python������Ƶҳ������" << endl;
    py.header();
    py.footer();
    py.left();
    py.content();
}

int main() {
    test01();
    system("pause");
    return 0;

}

