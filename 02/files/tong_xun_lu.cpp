#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//1.��װ������ʾ����
void showMenu(){
    cout << "**********************" << endl;
    cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
    cout << "***** 1.�����ϵ�� *****" << endl;
    cout << "***** 2.��ʾ��ϵ�� *****" << endl;
    cout << "***** 3.ɾ����ϵ�� *****" << endl;
    cout << "***** 4.������ϵ�� *****" << endl;
    cout << "***** 5.�޸���ϵ�� *****" << endl;
    cout << "***** 6.�����ϵ�� *****" << endl;
    cout << "**********************" << endl;
}

//�����ϵ�˽ṹ��
struct Person{
    //����
    string m_Name;
    //�Ա� 1.�� 2.Ů
    int m_Sex;
    //����
    int m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
    };

//���ͨѶ¼�ṹ��
struct AddressBooks{
    //ͨѶ¼�б������ϵ�˵�����
    struct Person personArray[MAX];
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};

//1.�����ϵ��
void addPerson(AddressBooks * abs){
    //�ж�ͨѶ¼�Ƿ�����,������˾Ͳ������
    if(abs->m_Size ==MAX){
        cout << "ͨѶ¼����,�޷����" << endl;
        return ;
    }
    else{
        //��Ӿ�����ϵ��
        //����
        string name;
        cout << "����������:" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name=name;
        //�Ա�
        int sex=0;
        cout << "�������Ա�:" << endl;
        cout << "1:�� 2:Ů" << endl;

        while (true){
            //ֻҪ����Ĳ���1����2,��Ҫ�ظ�����
            cin >> sex;
            if(sex ==1 || sex ==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout << "��������Ա�����,������1:��,2:Ů" << endl;
        }


        //����
        cout << "����������:" << endl;
        int age=0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age=age;
        //�绰
        cout << "������绰:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone=phone;
        //סַ
        cout << "������סַ:" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //����ͨѶ¼�е�����
        abs->m_Size++;
        cout << "��ϲ,����ӳɹ�һ���û�" << endl;


    }
    system("pause");//�밴���������
    system("cls");  //��������
}

//2.��װ��ʾ��ϵ����Ϣ
void showPerson(AddressBooks * abs){
    if(abs->m_Size==0){
        //û��,��ʾΪ��
        cout << "ͨѶ¼û��" << endl;
    }{
        for(int i=0;i<abs->m_Size;i++){
            cout << "����:" << abs->personArray[i].m_Name << "\t";
            //cout << "�Ա�:" << abs->personArray[i].m_Sex << "  ";//Ĭ����1��2,������,�޸�Ϊ�����
            //abs->personArray[i].m_Sex==1 ? cout << "�Ա�:��  " : cout << "�Ա�:Ů  "; //�������
            cout << "�Ա�:" << (abs->personArray[i].m_Sex==1 ? "��":"Ů") << "\t";
            cout << "����:" << abs->personArray[i].m_Age << "\t";
            cout << "�绰:" << abs->personArray[i].m_Phone << "\t";
            cout << "סַ:" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");//�밴���������
    system("cls");  //��������
}

//������ϵ���Ƿ����,�������,������ϵ���������е�����,���������ڷ���-1
//����1:ͨѶ¼ ����2:����
int isExist(AddressBooks * abs,string name){
    for(int i=0;i<abs->m_Size;i++){
        if(abs->personArray[i].m_Name==name){
            //�ҵ�����,���ر��
            return i;
        }
    }
    //û���ҵ���,����-1
    return -1;
}

//3.ɾ��ָ����ϵ��
void deletePerson(AddressBooks * abs){
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;
    //ret==-1,δ�鵽,ret!=-1�鵽��
    int ret=isExist(abs,name);
    if(ret!=-1){
        //�ҵ�����
        for(int i=ret;i<abs->m_Size;i++){
            //����ǰ��
            abs->personArray[i]=abs->personArray[i+1]; //������5��һ��,����ɵ��
            /*abs->personArray[i].m_Name=abs->personArray[i+1].m_Name;
            abs->personArray[i].m_Sex=abs->personArray[i+1].m_Sex;
            abs->personArray[i].m_Age=abs->personArray[i+1].m_Age;
            abs->personArray[i].m_Phone=abs->personArray[i+1].m_Phone;
            abs->personArray[i].m_Addr=abs->personArray[i+1].m_Addr;*/
        }
        abs->m_Size--;
        cout << "ɾ���ɹ�" << endl;
    }else{
        cout << "���޴���" << endl;
    }

    system("pause");//�밴���������
    system("cls");  //��������
}

//4.����ָ����ϵ��
void findPerson(AddressBooks * abs){
    cout << "������Ҫ���ҵ���ϵ����Ϣ" << endl;
    string name;
    cin >> name;
    //ret==-1,δ�鵽,ret!=-1�鵽��
    int ret=isExist(abs,name);
    if(ret!=-1){
        cout << "����:" << abs->personArray[ret].m_Name << "\t";
        cout << "�Ա�:" << (abs->personArray[ret].m_Sex==1 ? "��":"Ů") << "\t";
        cout << "����:" << abs->personArray[ret].m_Age << "\t";
        cout << "�绰:" << abs->personArray[ret].m_Phone << "\t";
        cout << "סַ:" << abs->personArray[ret].m_Addr << endl;
        cout << endl;
    }else{
        cout << "���޴���" << endl;
    }

    system("pause");//�밴���������
    system("cls");  //��������
}

//5.revise,modify�޸���ϵ��
void revisePerson(AddressBooks * abs){
    cout << "������Ҫ�޸ĵ���ϵ��:" << endl;
    string name1;
    cin >> name1;
    int ret=isExist(abs,name1);
    if(ret!=-1){
        //�ҵ�,�޸�
        //����
        cout << "����������" << endl;
        string name;
        cin >> name;
        abs->personArray[ret].m_Name=name;
        //�Ա�
        cout << "�������Ա�,1:��,2:Ů" << endl;
        int sex=0;
        while (true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                //������ȷ,�˳�ѭ��
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cout << "��������Ա�����,������1:��,2:Ů" << endl;
        }
        //����
        cout << "����������:" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].m_Age=age;
        //�绰
        cout << "������绰:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone=phone;
        //סַ
        cout << "�������ַ" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr=address;
        cout << "���³ɹ�" << endl;

    }else{
        //û�ҵ�
        cout << "���޴���" << endl;
    }
    system("pause");//�밴���������
    system("cls");  //��������
}

//6.�����ϵ��
void cleanPerson(AddressBooks * abs){
    //ֱ�ӽ�ͨѶ¼�г��ȱ�Ϊ0
    abs->m_Size=0;
    cout << "ͨѶ¼�Ѿ����" << endl;
    system("pause");//�밴���������
    system("cls");  //��������
}

int main() {

    //����ͨѶ¼�ṹ�����
    AddressBooks abs;
    //��ʼ����ͨѶ¼�е�ǰ��Ա����
    abs.m_Size=0;
    //�����û��������
    int select =0;
    while(true){           //ʹ��whileѭ��,ֻ��ִ��0��ʱ��,�λ᷵��0,���˳�,��Ȼ�᲻ͣѭ��
        //��ʾ�˵�
        showMenu();

        cin >> select;

        switch (select){
            case 0 :  //�˳�
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;  //��������

            case 1 :  //�����ϵ��
                addPerson(&abs); //���õ�ַ���ݿ�������ʵ�ʲ���
                break;
            case 2 :  //��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3 :  //ɾ����ϵ��
                deletePerson(&abs);
            /*//���Դ���
            {//case���볤�Ļ�Ҫ��{}������
                cout << "������ɾ������ϵ�˵�����:" << endl;
                string name;
                cin >> name;
                if (isExist(&abs, name) == -1) {
                    //û�ҵ�
                    cout << "���޴���" << endl;
                } else {
                    //�ҵ���
                    cout << "�ҵ�����" << endl;
                }
            }*/
                break;
            case 4 :  //������ϵ��
                findPerson(&abs);
                break;
            case 5 :  //�޸���ϵ��
                revisePerson(&abs);
                break;
            case 6 :  //�����ϵ��
                cleanPerson(&abs);
                break;

            default :
                return 0;
        }
    }
    return 0;
}
