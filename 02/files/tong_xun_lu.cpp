#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
//1.封装函数显示界面
void showMenu(){
    cout << "**********************" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "**********************" << endl;
}

//设计联系人结构体
struct Person{
    //姓名
    string m_Name;
    //性别 1.男 2.女
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
    };

//设计通讯录结构体
struct AddressBooks{
    //通讯录中保存的联系人的数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人个数
    int m_Size;
};

//1.添加联系人
void addPerson(AddressBooks * abs){
    //判断通讯录是否已满,如果满了就不再添加
    if(abs->m_Size ==MAX){
        cout << "通讯录已满,无法添加" << endl;
        return ;
    }
    else{
        //添加具体联系人
        //姓名
        string name;
        cout << "请输入姓名:" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name=name;
        //性别
        int sex=0;
        cout << "请输入性别:" << endl;
        cout << "1:男 2:女" << endl;

        while (true){
            //只要输入的不是1或者2,就要重复输入
            cin >> sex;
            if(sex ==1 || sex ==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout << "你输入的性别有误,请输入1:男,2:女" << endl;
        }


        //年龄
        cout << "请输入年龄:" << endl;
        int age=0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age=age;
        //电话
        cout << "请输入电话:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone=phone;
        //住址
        cout << "请输入住址:" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //更新通讯录中的人数
        abs->m_Size++;
        cout << "恭喜,你添加成功一个用户" << endl;


    }
    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

//2.封装显示联系人信息
void showPerson(AddressBooks * abs){
    if(abs->m_Size==0){
        //没人,提示为空
        cout << "通讯录没人" << endl;
    }{
        for(int i=0;i<abs->m_Size;i++){
            cout << "姓名:" << abs->personArray[i].m_Name << "\t";
            //cout << "性别:" << abs->personArray[i].m_Sex << "  ";//默认是1和2,看不懂,修改为下面的
            //abs->personArray[i].m_Sex==1 ? cout << "性别:男  " : cout << "性别:女  "; //下面更简单
            cout << "性别:" << (abs->personArray[i].m_Sex==1 ? "男":"女") << "\t";
            cout << "年龄:" << abs->personArray[i].m_Age << "\t";
            cout << "电话:" << abs->personArray[i].m_Phone << "\t";
            cout << "住址:" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

//查找联系人是否存在,如果存在,返回联系人在数组中的索引,索引不存在返回-1
//参数1:通讯录 参数2:人名
int isExist(AddressBooks * abs,string name){
    for(int i=0;i<abs->m_Size;i++){
        if(abs->personArray[i].m_Name==name){
            //找到人了,返回编号
            return i;
        }
    }
    //没有找到人,返回-1
    return -1;
}

//3.删除指定联系人
void deletePerson(AddressBooks * abs){
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    //ret==-1,未查到,ret!=-1查到了
    int ret=isExist(abs,name);
    if(ret!=-1){
        //找到此人
        for(int i=ret;i<abs->m_Size;i++){
            //数据前移
            abs->personArray[i]=abs->personArray[i+1]; //和下面5行一样,我是傻逼
            /*abs->personArray[i].m_Name=abs->personArray[i+1].m_Name;
            abs->personArray[i].m_Sex=abs->personArray[i+1].m_Sex;
            abs->personArray[i].m_Age=abs->personArray[i+1].m_Age;
            abs->personArray[i].m_Phone=abs->personArray[i+1].m_Phone;
            abs->personArray[i].m_Addr=abs->personArray[i+1].m_Addr;*/
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }else{
        cout << "查无此人" << endl;
    }

    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

//4.查找指定联系人
void findPerson(AddressBooks * abs){
    cout << "请输入要查找的联系人信息" << endl;
    string name;
    cin >> name;
    //ret==-1,未查到,ret!=-1查到了
    int ret=isExist(abs,name);
    if(ret!=-1){
        cout << "姓名:" << abs->personArray[ret].m_Name << "\t";
        cout << "性别:" << (abs->personArray[ret].m_Sex==1 ? "男":"女") << "\t";
        cout << "年龄:" << abs->personArray[ret].m_Age << "\t";
        cout << "电话:" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址:" << abs->personArray[ret].m_Addr << endl;
        cout << endl;
    }else{
        cout << "查无此人" << endl;
    }

    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

//5.revise,modify修改联系人
void revisePerson(AddressBooks * abs){
    cout << "请输入要修改的联系人:" << endl;
    string name1;
    cin >> name1;
    int ret=isExist(abs,name1);
    if(ret!=-1){
        //找到,修改
        //姓名
        cout << "请输入姓名" << endl;
        string name;
        cin >> name;
        abs->personArray[ret].m_Name=name;
        //性别
        cout << "请输入性别,1:男,2:女" << endl;
        int sex=0;
        while (true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                //输入正确,退出循环
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cout << "你输入的性别有误,请输入1:男,2:女" << endl;
        }
        //年龄
        cout << "请输入年龄:" << endl;
        int age;
        cin >> age;
        abs->personArray[ret].m_Age=age;
        //电话
        cout << "请输入电话:" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone=phone;
        //住址
        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr=address;
        cout << "更新成功" << endl;

    }else{
        //没找到
        cout << "查无此人" << endl;
    }
    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

//6.清空联系人
void cleanPerson(AddressBooks * abs){
    //直接将通讯录中长度变为0
    abs->m_Size=0;
    cout << "通讯录已经清空" << endl;
    system("pause");//请按任意键继续
    system("cls");  //清屏操作
}

int main() {

    //创建通讯录结构体变量
    AddressBooks abs;
    //初始化中通讯录中当前人员个数
    abs.m_Size=0;
    //创建用户输入变量
    int select =0;
    while(true){           //使用while循环,只有执行0的时候,参会返回0,才退出,不然会不停循环
        //显示菜单
        showMenu();

        cin >> select;

        switch (select){
            case 0 :  //退出
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;  //结束程序

            case 1 :  //添加联系人
                addPerson(&abs); //利用地址传递可以修饰实际参数
                break;
            case 2 :  //显示联系人
                showPerson(&abs);
                break;
            case 3 :  //删除联系人
                deletePerson(&abs);
            /*//测试代码
            {//case代码长的话要用{}括起来
                cout << "请输入删除的联系人的姓名:" << endl;
                string name;
                cin >> name;
                if (isExist(&abs, name) == -1) {
                    //没找到
                    cout << "查无此人" << endl;
                } else {
                    //找到了
                    cout << "找到此人" << endl;
                }
            }*/
                break;
            case 4 :  //查找联系人
                findPerson(&abs);
                break;
            case 5 :  //修改联系人
                revisePerson(&abs);
                break;
            case 6 :  //清空联系人
                cleanPerson(&abs);
                break;

            default :
                return 0;
        }
    }
    return 0;
}
