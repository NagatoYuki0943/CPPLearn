#include "workerManager.h"

//构造函数
WorkerManager::WorkerManager() {

	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in); //读文件
	if (!ifs.is_open()) {
		//文件不存在
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数为0
		this->m_EmpNum = 0;
		//初始化数组指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //不往构造函数下面走了
	}
	//2.文件存在但是为空
	char ch;
	ifs >> ch; //读取一个字符
	if (ifs.eof()) {
		//ifs.eof()代表文件尾,说明文件读完了
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数为0
		this->m_EmpNum = 0;
		//初始化数组指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //不往构造函数下面走了
	}

	//3.文件存在不为空
	//有数据,更改空文件标记,改为不为空
	this->m_FileIsEmpty = false;

	int num = this->get_EmpNum();
	cout << "职工人数是:" << num << endl;
	this -> m_EmpNum = num;

	//在堆区创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	//测试
	/*for (int i = 0; i < num; i++) {
		cout << "职工编号:" << this->m_EmpArray[i]->m_Id
			<< " 职工姓名:" << this->m_EmpArray[i]->m_Name
			<< " 职工部门" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

//析构函数
WorkerManager::~WorkerManager() {
	//删除堆区数据
	if (this->m_EmpArray != NULL) {
		//1.删除每个对象
		for (int i = 0; i < this->m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] == NULL;
		}
		//2.再删除整体指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//展示菜单函数
void WorkerManager::Show_Menu() {
	cout << "************************************" << endl;
	cout << "******* 欢迎使用职工管理系统! ******" << endl;
	cout << "********** 0.退出管理程序 **********" << endl;
	cout << "********** 1.增加职工信息 **********"<< endl;
	cout << "********** 2.显示职工信息 **********" << endl;
	cout << "********** 3.删除离职职工 **********" << endl;
	cout << "********** 4.修改职工信息 **********" << endl;
	cout << "********** 5.查找职工信息 **********" << endl;
	cout << "********** 6.按照编号排序 **********" << endl;
	cout << "********** 7.清空所有文档 **********" << endl;
	cout << "************************************" << endl;
}

//退出功能
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}

//添加职工
void WorkerManager::Add_Emp() {
	cout << "请输入添加的职工数量" << endl;
	int addNum = 0; //保存用户的输入数量
	cin >> addNum;
	if (addNum > 0) {
		//添加
		//计算添加的新的空间大小
		int newSize = this->m_EmpNum + addNum; //新空间大小=原来保存人数+新增人数
		//开辟新空间
		//Worker **是指向Worker*的指针,用两个**指向
		Worker ** newSpace=new Worker* [newSize];

		//将原来空间的数据拷贝到新空间下
		if (this->m_EmpNum != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;      //职工编号
			string name; //职工姓名
			int dSelect; //部门选择

			//判断id是否重复
			while (true) {
				cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
				cin >> id;
				bool flag = this->Compare_Id(id);
				if (flag) {
					//没有重复id
					break;
				}
				else {
					cout << "您输入的id重复,请换一个id" << endl;
				}
			}


			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;

			Worker* worker = NULL;
			while (true) {
				cout << "请选择该职工的岗位: 1.普通职工  2.经理  3.老板" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) {
					//分别传入不同的子类

					switch (dSelect)
					{
					case 1:
						worker = new Employee(id, name, 1);
						break;
					case 2:
						worker = new Manager(id, name, 2);
						break;
					case 3:
						worker = new Boss(id, name, 3);
						break;
					}
					//将创建的职工指针,保存到数组中
					newSpace[this->m_EmpNum + i] = worker;
					break; //终止外面while(true)的循环
				}
				cout << "你输入的职业有误" << endl;
			}

		}

		//释放原有空间
		delete[]  m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更改新空间的大小
		this->m_EmpNum = newSize;

		//成功添加后,保存到文件中
		this->save();

		//添加成功,更改空文件标记,改为不为空
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新员工" << endl;
	}
	else {
		cout << "输入的数量有误" << endl;
	}

	//按任意键后清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //写文件
	//将每个人的数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

//统计人数
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++; //统计人数
	}
	return num;
}

//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while(ifs >> id && ifs >> name && ifs >> dId){
		Worker* worker = NULL;
		if (dId == 1) {
			//普通职工
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2){
			//经理
			worker = new Manager(id, name, dId);
		}
		else {
			//老板
			worker = new Boss(id, name, dId);
		}
		//存入成员数组中
		this->m_EmpArray[index] = worker;
		index++;
	}

	//关闭文件
	ifs.close();
}

//显示员工
void WorkerManager::Show_Emp() {
	//判断文件是否为空或者存在
	if (this->m_FileIsEmpty) {
		//文件为空
		cout << "文件为空或者不存在" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//判断员工是否存在,如果存在,返回职工所在数组位置,不存在返回-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for(int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//找到了,index==i
			index = i;
			break; //退出循环
		}
	}
	return index;
}

//删除员工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;

	}
	else {
		//按照职工编号删除
		cout << "请输入想要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) {
			//职工存在,并且要删除index位置上的员工
			for (int i = index; i < this->m_EmpNum-1;i++ ){
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//人数-1
			this->m_EmpNum--;
			//同步更新到文件中
			this->save();

			cout << "删除成功" << endl;
		}
		else {
			//职工不存在
			cout << "删除失败,未找到该职工" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");

}

//修改职工
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	}
	else {
		cout << "请输入修改的职工编号" << endl;
		int id;
		cin >> id;
		int index=this->IsExist(id);
		if(index != -1) {
			//查找到编号的职工

			//删除源数据
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到了ID=" << id << "的员工,请输入新的职工编号" << endl;
			cin >> newId;
			cout << "请输入新的姓名" << endl;
			cin >> newName;

			Worker* worker=NULL;

			while (true) {
				cout << "请输入新的岗位 1.普通职工 2.经理 3.老板" << endl;
				cin >> dSelect;
				if (dSelect==1 || dSelect==2 || dSelect==3) {
					//分别传入不同的子类
					switch (dSelect)
					{
					case 1:
						worker = new Employee(newId,newName,dSelect);
						break;
					case 2:
						worker = new Manager(newId, newName, dSelect);
						break;
					case 3:
						worker = new Boss(newId, newName, dSelect);
						break;
					default:
						break;
					}
					break;
				}
			}

			//更新数据
			this->m_EmpArray[index] = worker;

			//保存文件
			this->save();

			//告诉用户修改成功
			cout << "修改成功" << endl;
		}
		else {
			//未找到员工'
			cout << "员工不存在" << endl;
		}
	}

	//清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空" << endl;
	}
	else {
		int select = 0;
		while (true) {
			cout << "请输入查找的方式: 1.按id查找 2.按姓名查找" << endl;
			cin >> select;
			if (select == 1 || select == 2) {
				if (select == 1) {
					//按id查找
					int id;
					cout << "请输入职工编号" << endl;
					cin >> id;
					int res=IsExist(id);
					if (res != -1) {
						//有这个人
						cout << "查找成功,信息如下:" << endl;
						//显示职工信息
						this->m_EmpArray[res]->showInfo();
					}
					else {
						cout << "查无此人" << endl;
					}
				}
				else {
					//按姓名查找
					string name = "";
					cout << "请输入职工姓名" << endl;
					cin >> name;
					//加入判读查找是否查到的标志
					bool flag = false;
					for (int i = 0; i < this->m_EmpNum; i++) {
						if (this->m_EmpArray[i]->m_Name == name) {
							cout << "查找成功,职工编号为:" << this->m_EmpArray[i]->m_Id << "的员工信息如下"<< endl;
							//调用显示员工的信息
							this->m_EmpArray[i]->showInfo();
							flag = true;
							//这里如果有break,就只会输出第一个人的信息,后面的就不会了

						}
					}
					if (flag == false) {
						cout << "查找失败,查无此人" << endl;
					}
				}
				break;
			}
		}
	}

	//刷新页面
	system("pause");
	system("cls");
}

//按照编号排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		//文件不存在
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择 1.按照id升序 2.按照id降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++) {
			int minOrMax=i; //声明最小值或者最大值
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					//升序排列
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				else {
					//降序
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			//判断一开始的最小值或者最大值是否是计算的最小值或最大值
			if (i != minOrMax) {
				//说明不是一开始的值
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = tmp;
			}
		}
		this->save(); //排序后的结果保存到文件中
		cout << "排序成功,排序后的结果是:" << endl;
		this->Show_Emp(); //展示所有职工,这个函数有按任意键清空屏幕,这里就不用定义了
	}
}

//清空文件
void WorkerManager::Clean_File() {
	cout << "确定清空吗? 1.清空 2.不清空" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//1.清空文件
		ofstream ofs(FILENAME,ios::trunc);  //trunc的作用是如果文件存在,删除在创建
		ofs.close();

		//2.清空堆区数据
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				//1.删除每个对象
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//2.删除堆区的数组
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功!" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}

//将输入的id与已经存在的id进行比较
bool WorkerManager::Compare_Id(int newId) {
	//定义标志,默认true认为没有重复值
	bool flag = true;
	//获取所有用户id与新d比较
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (newId == this->m_EmpArray[i]->m_Id) {
			//有重复id
			flag = false;
		}
	}
	return flag;
}