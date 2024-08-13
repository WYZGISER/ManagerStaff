#include<iostream>
using namespace std;
#include"workerManager.h"

#include"worker.h"

#include"employee.h"
#include"boss.h"
#include"manager.h"


//公司中职工分为三类：普通职工、经历、老板
//显示信息时：需要显示职工编号、职工姓名、职工岗位以及职责
//普通员工：完成经理交给的任务
//经理职责：完成老板交给的任务，并下发任务给员工
//老板职责：管理公司所有事务

//管理系统中需要实现以下功能
//退出管理系统
//增加职工信息：实现批量增加职工功能，将信息录入到文件中 职工信息为：职工编号、姓名、部门编号’
//显示职工信息：显示公司内所有的职工信息
//删除离职员工：按照编号删除指定员工
//修改员工信息：按照编号修改职工个人信息



//创建管理类
//1、与用户的沟通菜单界面
//2、对职工增删改查操作
//3、与文件的读写交互

//创建职工抽象类
//职工分类;普通员工 经理 老板
//将三种员工抽象到一个类：职工编号 职工姓名 职工所在部门编号
//职工的行为：岗位职责信息描述，获取岗位名称

//添加职工
//功能描述：批量添加职工，并保存到文件
//功能分析：
//用户在批量创建时，可能会创建不同种类的职工
//如果想要将不同种类的员工放到一个数组中，可以将所有员工的指针维护到一个数组里
//如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker**的指针维护

//文件交互：写文件
//功能描述：对文件进行读写

//文件交互：读文件
//第一次使用：文件未创建
//文件存在，但用户数据被清空
//文件存在，并且保存用户所有数据





int main() {

	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1,"刘一",1);
	worker->showInfo();
	 

	Worker* worker2 = NULL;
	worker2 = new Boss(2, "关二", 3);
	worker2->showInfo();

	Worker* worker3;
	worker3 = new Manager(3, "张三",2);
	worker3->showInfo();*/

	

	//实例化管理者对象
	WorkerManadger wm;

	//用户的选择
	int choice = 0;

	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();
		
		cout << "请输入您的选择" << endl;
		cin >> choice;//接收用户的选项

		switch (choice)
		{

		case 0://退出系统

			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
		/*{
			int ret = wm.IsExist(1000);
			if (ret != -1)
			{
				cout << "存在" << endl;
			}
			else
			{
				cout << "不存在" << endl;
			}
			break;
		
		}*/
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://对职工进行排序
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}

	

	system("pause");
	return 0;
}