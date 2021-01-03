#include <iostream>

using namespace std;

/**
 * cube��,�����������������
 * �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
 */
class Cube {
    //Ĭ��˽��
    int m_l, m_w, m_h;
public:
    //���ó����
    void set_lmh(int l, int w, int h) {
        m_l = l;
        m_w = w;
        m_h = h;
    }

    //���س����
    int getL() {
        return m_l;
    }

    int getW() {
        return m_w;
    }

    int getH() {
        return m_h;
    }

    //���
    int calculateArea() {
        return 2 * (m_l * m_w + m_l * m_h + m_w * m_h);
    }

    //���
    int calculateVolume() {
        return m_l * m_w * m_h;
    }

    //���ó�Ա�����ж������������Ƿ����
    //ֻ�ô���һ��Cube����,��Ϊ���������һ��Cube��
    bool isSame00(Cube &c1) {  //���ô���,��ʡ�ڴ�
        if (c1.m_l == m_l && c1.m_w == m_w && c1.m_h == m_h) {
            return true;
        } else {
            return false;
        }
    }
};

//����ȫ�ֺ����ж������������Ƿ����
bool isSamebyClass(Cube &c1, Cube &c2) {  //���ô���,��ʡ�ڴ�
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
        return true;
    } else {
        return false;
    }
};

int main() {
    Cube c1;
    //���ó����
    c1.set_lmh(10, 20, 30);
    cout << "�����:" << c1.calculateArea() << endl;  //2200
    cout << "�����:" << c1.calculateVolume() << endl;//6000
    Cube c2;
    c2.set_lmh(10, 20, 30);
    //ʹ��ȫ�ֺ���
    cout << "ȫ�ֺ����ж�:\t" << (isSamebyClass(c1, c2) == true ? "���" : "�����") << endl;
    //ʹ�ó�Ա����,ֻ��Ҫ����һ��
    cout << "��Ա�����ж�:\t" << (c2.isSame00(c1) == true ? "���" : "�����") << endl;

    system("pause");
    return 0;
}

/*bool isSame00(Cube &c1,Cube &c2){  //���ô���,��ʡ�ڴ�
    if(c1.m_l==c2.m_l && c1.m_w==c2.m_w && c1.m_h==c2.m_h){
        return true;
    }else{
        return false;
    }
}*/
