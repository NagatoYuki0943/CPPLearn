#include "workerManager.h"

//���캯��
WorkerManager::WorkerManager() {

	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in); //���ļ�
	if (!ifs.is_open()) {
		//�ļ�������
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //�������캯����������
	}
	//2.�ļ����ڵ���Ϊ��
	char ch;
	ifs >> ch; //��ȡһ���ַ�
	if (ifs.eof()) {
		//ifs.eof()�����ļ�β,˵���ļ�������
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����Ϊ0
		this->m_EmpNum = 0;
		//��ʼ������ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //�������캯����������
	}

	//3.�ļ����ڲ�Ϊ��
	//������,���Ŀ��ļ����,��Ϊ��Ϊ��
	this->m_FileIsEmpty = false;

	int num = this->get_EmpNum();
	cout << "ְ��������:" << num << endl;
	this -> m_EmpNum = num;

	//�ڶ�����������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	//����
	/*for (int i = 0; i < num; i++) {
		cout << "ְ�����:" << this->m_EmpArray[i]->m_Id
			<< " ְ������:" << this->m_EmpArray[i]->m_Name
			<< " ְ������" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

//��������
WorkerManager::~WorkerManager() {
	//ɾ����������
	if (this->m_EmpArray != NULL) {
		//1.ɾ��ÿ������
		for (int i = 0; i < this->m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] == NULL;
		}
		//2.��ɾ������ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//չʾ�˵�����
void WorkerManager::Show_Menu() {
	cout << "************************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ! ******" << endl;
	cout << "********** 0.�˳�������� **********" << endl;
	cout << "********** 1.����ְ����Ϣ **********"<< endl;
	cout << "********** 2.��ʾְ����Ϣ **********" << endl;
	cout << "********** 3.ɾ����ְְ�� **********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ **********" << endl;
	cout << "********** 5.����ְ����Ϣ **********" << endl;
	cout << "********** 6.���ձ������ **********" << endl;
	cout << "********** 7.��������ĵ� **********" << endl;
	cout << "************************************" << endl;
}

//�˳�����
void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

//���ְ��
void WorkerManager::Add_Emp() {
	cout << "��������ӵ�ְ������" << endl;
	int addNum = 0; //�����û�����������
	cin >> addNum;
	if (addNum > 0) {
		//���
		//������ӵ��µĿռ��С
		int newSize = this->m_EmpNum + addNum; //�¿ռ��С=ԭ����������+��������
		//�����¿ռ�
		//Worker **��ָ��Worker*��ָ��,������**ָ��
		Worker ** newSpace=new Worker* [newSize];

		//��ԭ���ռ�����ݿ������¿ռ���
		if (this->m_EmpNum != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;      //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��

			//�ж�id�Ƿ��ظ�
			while (true) {
				cout << "�������" << i + 1 << "����ְ���ı��" << endl;
				cin >> id;
				bool flag = this->Compare_Id(id);
				if (flag) {
					//û���ظ�id
					break;
				}
				else {
					cout << "�������id�ظ�,�뻻һ��id" << endl;
				}
			}


			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			Worker* worker = NULL;
			while (true) {
				cout << "��ѡ���ְ���ĸ�λ: 1.��ְͨ��  2.����  3.�ϰ�" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) {
					//�ֱ��벻ͬ������

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
					//��������ְ��ָ��,���浽������
					newSpace[this->m_EmpNum + i] = worker;
					break; //��ֹ����while(true)��ѭ��
				}
				cout << "�������ְҵ����" << endl;
			}

		}

		//�ͷ�ԭ�пռ�
		delete[]  m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����¿ռ�Ĵ�С
		this->m_EmpNum = newSize;

		//�ɹ���Ӻ�,���浽�ļ���
		this->save();

		//��ӳɹ�,���Ŀ��ļ����,��Ϊ��Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����Ա��" << endl;
	}
	else {
		cout << "�������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //д�ļ�
	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//ͳ������
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++; //ͳ������
	}
	return num;
}

//��ʼ��Ա��
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
			//��ְͨ��
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2){
			//����
			worker = new Manager(id, name, dId);
		}
		else {
			//�ϰ�
			worker = new Boss(id, name, dId);
		}
		//�����Ա������
		this->m_EmpArray[index] = worker;
		index++;
	}

	//�ر��ļ�
	ifs.close();
}

//��ʾԱ��
void WorkerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ�ջ��ߴ���
	if (this->m_FileIsEmpty) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ����,�������,����ְ����������λ��,�����ڷ���-1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for(int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//�ҵ���,index==i
			index = i;
			break; //�˳�ѭ��
		}
	}
	return index;
}

//ɾ��Ա��
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ��" << endl;

	}
	else {
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) {
			//ְ������,����Ҫɾ��indexλ���ϵ�Ա��
			for (int i = index; i < this->m_EmpNum-1;i++ ){
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//����-1
			this->m_EmpNum--;
			//ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else {
			//ְ��������
			cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");

}

//�޸�ְ��
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else {
		cout << "�������޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int index=this->IsExist(id);
		if(index != -1) {
			//���ҵ���ŵ�ְ��

			//ɾ��Դ����
			delete this->m_EmpArray[index];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��ID=" << id << "��Ա��,�������µ�ְ�����" << endl;
			cin >> newId;
			cout << "�������µ�����" << endl;
			cin >> newName;

			Worker* worker=NULL;

			while (true) {
				cout << "�������µĸ�λ 1.��ְͨ�� 2.���� 3.�ϰ�" << endl;
				cin >> dSelect;
				if (dSelect==1 || dSelect==2 || dSelect==3) {
					//�ֱ��벻ͬ������
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

			//��������
			this->m_EmpArray[index] = worker;

			//�����ļ�
			this->save();

			//�����û��޸ĳɹ�
			cout << "�޸ĳɹ�" << endl;
		}
		else {
			//δ�ҵ�Ա��'
			cout << "Ա��������" << endl;
		}
	}

	//����
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else {
		int select = 0;
		while (true) {
			cout << "��������ҵķ�ʽ: 1.��id���� 2.����������" << endl;
			cin >> select;
			if (select == 1 || select == 2) {
				if (select == 1) {
					//��id����
					int id;
					cout << "������ְ�����" << endl;
					cin >> id;
					int res=IsExist(id);
					if (res != -1) {
						//�������
						cout << "���ҳɹ�,��Ϣ����:" << endl;
						//��ʾְ����Ϣ
						this->m_EmpArray[res]->showInfo();
					}
					else {
						cout << "���޴���" << endl;
					}
				}
				else {
					//����������
					string name = "";
					cout << "������ְ������" << endl;
					cin >> name;
					//�����ж������Ƿ�鵽�ı�־
					bool flag = false;
					for (int i = 0; i < this->m_EmpNum; i++) {
						if (this->m_EmpArray[i]->m_Name == name) {
							cout << "���ҳɹ�,ְ�����Ϊ:" << this->m_EmpArray[i]->m_Id << "��Ա����Ϣ����"<< endl;
							//������ʾԱ������Ϣ
							this->m_EmpArray[i]->showInfo();
							flag = true;
							//���������break,��ֻ�������һ���˵���Ϣ,����ľͲ�����

						}
					}
					if (flag == false) {
						cout << "����ʧ��,���޴���" << endl;
					}
				}
				break;
			}
		}
	}

	//ˢ��ҳ��
	system("pause");
	system("cls");
}

//���ձ������
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		//�ļ�������
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ�� 1.����id���� 2.����id����" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++) {
			int minOrMax=i; //������Сֵ�������ֵ
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {
					//��������
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				else {
					//����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ����Сֵ�������ֵ�Ƿ��Ǽ������Сֵ�����ֵ
			if (i != minOrMax) {
				//˵������һ��ʼ��ֵ
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = tmp;
			}
		}
		this->save(); //�����Ľ�����浽�ļ���
		cout << "����ɹ�,�����Ľ����:" << endl;
		this->Show_Emp(); //չʾ����ְ��,��������а�����������Ļ,����Ͳ��ö�����
	}
}

//����ļ�
void WorkerManager::Clean_File() {
	cout << "ȷ�������? 1.��� 2.�����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//1.����ļ�
		ofstream ofs(FILENAME,ios::trunc);  //trunc������������ļ�����,ɾ���ڴ���
		ofs.close();

		//2.��ն�������
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				//1.ɾ��ÿ������
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//2.ɾ������������
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�!" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

//�������id���Ѿ����ڵ�id���бȽ�
bool WorkerManager::Compare_Id(int newId) {
	//�����־,Ĭ��true��Ϊû���ظ�ֵ
	bool flag = true;
	//��ȡ�����û�id����d�Ƚ�
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (newId == this->m_EmpArray[i]->m_Id) {
			//���ظ�id
			flag = false;
		}
	}
	return flag;
}