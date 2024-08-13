#include"workerManager.h"
WorkerManadger::WorkerManadger() {


	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;

		//��ʼ������
		//��ʼ����¼������
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArrzay = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	} 

	//���ļ����ڣ�����Ϊ��ʱ
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼������
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArrzay = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	//�ļ����ڲ��Ҽ�¼����
	int num = this->get_EmpNum();
	//cout << "ְ��������Ϊ��" << num << endl;
	this->m_EmpNum = num;//����m_EmpNum

	//���ٿռ�
	this->m_EmpArrzay = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArrzay[i]->m_Id << " "
			<< "ְ��������" << this->m_EmpArrzay[i]->m_Name << " "
			<< "ְ�����ţ�" << this->m_EmpArrzay[i]->getDeptName() << endl;

	}*/
	
}


//չʾ�˵�
void WorkerManadger::Show_Menu() {
	cout << "**********************************************************" << endl;
	cout << "*******************��ӭʹ��ְ��ϵͳ***********************" << endl;
	cout << "*******************0.�˳��������*************************" << endl;
	cout << "*******************1.����ְ����Ϣ*************************" << endl;
	cout << "*******************2.��ʾְ����Ϣ*************************" << endl;
	cout << "*******************3.ɾ��ְ����Ϣ*************************" << endl;
	cout << "*******************4.�޸�ְ����Ϣ*************************" << endl;
	cout << "*******************5.����ְ����Ϣ*************************" << endl;
	cout << "*******************6.���ձ������*************************" << endl;
	cout << "*******************7.��������ĵ�*************************" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ

void WorkerManadger::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

//�����ļ�
void WorkerManadger::save() {
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//������ķ�ʽ�����ļ�----д�ļ�

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArrzay[i]->m_Id << " "
			<< this->m_EmpArrzay[i]->m_Name << " "
			<< this->m_EmpArrzay[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
	
}

//���ְ��
void WorkerManadger::Add_Emp() {
	cout << "���������ְ����������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum>0)
	{
		//���
		//��������µĿռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�Ĵ�С=ԭ���Ŀռ��С+�û�����������

		//�����¿ռ�
		Worker**newSpace = new Worker* [newSize];

		//��ԭ���ռ��µ����ݿ������µĿռ���
		if (this->m_EmpArrzay!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArrzay[i];
			}
		}

		//������ʼ����µ�����
		for (size_t i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker ;

		}

		//�ͷ�ԭ�з��ռ�
		delete[] this->m_EmpArrzay;

		//�����¿ռ��ָ��
		this->m_EmpArrzay = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յ����
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󱣴����ļ���
		this->save();

		//��ʾ��ӳɹ�
		cout << "�ɹ������" << addNum << "��ְ��!" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	//������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//ͳ���ļ�������
int WorkerManadger::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ� ���ļ�
	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ�������ı���
		num++;
	}

	return num;
}

//��ʼ��Ա��
void WorkerManadger::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArrzay[index] = worker;

		index++;
	}

	//�ر��ļ�
	ifs.close();
}


//��ʾְ��
void WorkerManadger::show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���Ľӿ�
			this->m_EmpArrzay[i]->showInfo();
		}
	}
	//������������Ĳ���
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManadger::Del_Emp() {
	//�ж��ļ��Ƿ����
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//����ְ����Ž���ɾ��ְ��
		cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//˵��ְ���Ǵ��ڵģ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum-1; i++)//m_EmpNum-1:�����������һ��Ԫ��
			{
				this->m_EmpArrzay[i] = this->m_EmpArrzay[i + 1];
			}
			this->m_EmpNum--;//���������е���Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

		//�����������
		system("pause");
		system("cls");

	}

}

//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManadger::IsExist(int id) {
	int index = -1;
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArrzay[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			/*return i;*/
			break;
		}
	}
	//int i = 1;
	//while (i< this->m_EmpNum)
	//{
	//	if (this->m_EmpArrzay[i]->m_Id == id);
	//	{
	//		//�ҵ�ְ��
	//		index = i;
	//		/*return i;*/
	//		break;
	//	}
	//	i++;
	//}

	
	//cout << index << endl;
	return index;
	
}

//�޸�ְ��
void WorkerManadger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArrzay[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽���Ϊ��" << id << "��ְ���������������µ�ְ�����" << endl;
			cin >> newId;

			cout << "�������µ�ְ������" << endl;
			cin >> newName;

			cout << "�����λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2��ְ��" << endl;
			cout << "3���ϰ�" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
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

			//�������ݵ�������
			this->m_EmpArrzay[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//�����ݱ��浽�ļ���
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ�û�в��ҵ����û�" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManadger::Find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1������ְ���ı�Ų���" << endl;
		cout << "2������ְ������������" << endl;

		int select = 0;
		cin >> select;

		if (select== 1)
		{
			//����ְ���ı�Ų���
			int id;
			cout << "��������ҵ�ְ���ı���Ƕ���" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�,��ְ������Ϣ���£�" << endl;
				this->m_EmpArrzay[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if(select == 2)
		{
			//����ְ������������
			string name;
			cout << "���������ְ��������" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flas = false;//Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArrzay[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << m_EmpArrzay[i]->m_Id << "����Ϣ���£�" << endl;
					flas = true;

					this->m_EmpArrzay[i]->showInfo();
				}
			}
			if (flas == false)
			{
				cout << "���޴���" << endl;
			}
			

		}
		else
		{
			cout << "�������" << endl;
		}

		system("pause");
		system("cls");

	}
}

//����ļ�
void WorkerManadger::Clean_File() {
	cout << "ȷ�������" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME,ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArrzay!=NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete this->m_EmpArrzay[i];
				this->m_EmpArrzay[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArrzay;
			this->m_EmpArrzay = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}



WorkerManadger::~WorkerManadger() {//���������ͷŶ�������
	if (this->m_EmpArrzay!=NULL)
	{
		delete[] this->m_EmpArrzay;
		this->m_EmpArrzay = NULL;
	}
}