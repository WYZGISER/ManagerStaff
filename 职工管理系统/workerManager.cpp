#include"workerManager.h"
WorkerManadger::WorkerManadger() {


	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;

		//初始化属性
		//初始化记录的人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArrzay = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	} 

	//当文件存在，数据为空时
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化记录的人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArrzay = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}


	//文件存在并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工的人数为：" << num << endl;
	this->m_EmpNum = num;//更新m_EmpNum

	//开辟空间
	this->m_EmpArrzay = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArrzay[i]->m_Id << " "
			<< "职工姓名：" << this->m_EmpArrzay[i]->m_Name << " "
			<< "职工部门：" << this->m_EmpArrzay[i]->getDeptName() << endl;

	}*/
	
}


//展示菜单
void WorkerManadger::Show_Menu() {
	cout << "**********************************************************" << endl;
	cout << "*******************欢迎使用职工系统***********************" << endl;
	cout << "*******************0.退出管理程序*************************" << endl;
	cout << "*******************1.增加职工信息*************************" << endl;
	cout << "*******************2.显示职工信息*************************" << endl;
	cout << "*******************3.删除职工信息*************************" << endl;
	cout << "*******************4.修改职工信息*************************" << endl;
	cout << "*******************5.查找职工信息*************************" << endl;
	cout << "*******************6.安照编号排序*************************" << endl;
	cout << "*******************7.清空所有文档*************************" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
}

//退出系统

void WorkerManadger::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//保存文件
void WorkerManadger::save() {
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//用输出的方式来打开文件----写文件

	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArrzay[i]->m_Id << " "
			<< this->m_EmpArrzay[i]->m_Name << " "
			<< this->m_EmpArrzay[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
	
}

//添加职工
void WorkerManadger::Add_Emp() {
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum>0)
	{
		//添加
		//计算添加新的空间大小
		int newSize = this->m_EmpNum + addNum;//新空间的大小=原来的空间大小+用户的输入数量

		//开辟新空间
		Worker**newSpace = new Worker* [newSize];

		//将原来空间下的数据拷贝到新的空间下
		if (this->m_EmpArrzay!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArrzay[i];
			}
		}

		//批量开始添加新的数据
		for (size_t i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker ;

		}

		//释放原有发空间
		delete[] this->m_EmpArrzay;

		//更改新空间的指向
		this->m_EmpArrzay = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的情况
		this->m_FileIsEmpty = false;

		//成功添加后保存在文件中
		this->save();

		//提示添加成功
		cout << "成功添加了" << addNum << "新职工!" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键清屏回到上级目录
	system("pause");
	system("cls");
}

//统计文件中人数
int WorkerManadger::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//打开文件 读文件
	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数的变量
		num++;
	}

	return num;
}

//初始化员工
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
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else//老板
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArrzay[index] = worker;

		index++;
	}

	//关闭文件
	ifs.close();
}


//显示职工
void WorkerManadger::show_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序的接口
			this->m_EmpArrzay[i]->showInfo();
		}
	}
	//按任意键清屏的操作
	system("pause");
	system("cls");
}

//删除职工
void WorkerManadger::Del_Emp() {
	//判断文件是否存在
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号进行删除职工
		cout << "请输入想要删除职工的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//说明职工是存在的，并且要删除index位置上的职工
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum-1; i++)//m_EmpNum-1:数组中是最后一个元素
			{
				this->m_EmpArrzay[i] = this->m_EmpArrzay[i + 1];
			}
			this->m_EmpNum--;//更新数组中的人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}

		//按任意键清屏
		system("pause");
		system("cls");

	}

}

//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManadger::IsExist(int id) {
	int index = -1;
	
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArrzay[i]->m_Id == id)
		{
			//找到职工
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
	//		//找到职工
	//		index = i;
	//		/*return i;*/
	//		break;
	//	}
	//	i++;
	//}

	
	//cout << index << endl;
	return index;
	
}

//修改职工
void WorkerManadger::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			delete this->m_EmpArrzay[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到编号为：" << id << "的职工，请输入他的新的职工编号" << endl;
			cin >> newId;

			cout << "请输入新的职工姓名" << endl;
			cin >> newName;

			cout << "请输岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、职工" << endl;
			cout << "3、老板" << endl;

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

			//更新数据到数组中
			this->m_EmpArrzay[ret] = worker;

			cout << "修改成功" << endl;

			//把数据保存到文件中
			this->save();

		}
		else
		{
			cout << "修改失败，没有查找到改用户" << endl;
		}

	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManadger::Find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1、按照职工的编号查找" << endl;
		cout << "2、按照职工的姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select== 1)
		{
			//按照职工的编号查找
			int id;
			cout << "请输入查找的职工的编号是多少" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功,该职工的信息如下：" << endl;
				this->m_EmpArrzay[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if(select == 2)
		{
			//按照职工的姓名查找
			string name;
			cout << "请输入查找职工的姓名" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flas = false;//默认未找到职工

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArrzay[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" << m_EmpArrzay[i]->m_Id << "的信息如下：" << endl;
					flas = true;

					this->m_EmpArrzay[i]->showInfo();
				}
			}
			if (flas == false)
			{
				cout << "查无此人" << endl;
			}
			

		}
		else
		{
			cout << "输入错误" << endl;
		}

		system("pause");
		system("cls");

	}
}

//清空文件
void WorkerManadger::Clean_File() {
	cout << "确定清空吗" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME,ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArrzay!=NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete this->m_EmpArrzay[i];
				this->m_EmpArrzay[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArrzay;
			this->m_EmpArrzay = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}



WorkerManadger::~WorkerManadger() {//析构函数释放堆区数据
	if (this->m_EmpArrzay!=NULL)
	{
		delete[] this->m_EmpArrzay;
		this->m_EmpArrzay = NULL;
	}
}