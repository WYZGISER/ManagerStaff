#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

//案例描述
//公司今天招聘10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
//员工信息有：姓名 工资组成；部门分为策划 美术 研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key（部门编号）--- value（员工）
//分部门显示员工信息
//
//实现步骤
//1、创建10名员工，放到vector中
//2、遍历vector容器，取出每个员工，进行随机分组
//3、分组后，将员工部门编号作为key，具体员工作为value，放到multimap容器中
//4、分部门显示员工信息


class Worker {
public:
	string m_Name;
	int m_Salary;
};

//创建员工函数
void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999
		//将员工放进容器中
		v.push_back(worker);
	}
}

//员工分组函数
void setGroup(vector<Worker> &v,multimap<int,Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {

		//产生一个随机部门的编号
		int deptId = rand() % 3;//产生0、1、2的随机数
		
		//将员工插入分组中
		m.insert(make_pair(deptId, *it));

		for (multimap<int, Worker>::iterator mit = m.begin(); mit != m.end(); mit++) {

		}
	}
}

//分组显示员工
void showWorkerByGroup(multimap<int, Worker>& m) {

	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	cout << "策划部门的信息：" << endl;
	//统计策划部门多少人
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名是：" << pos->second.m_Name << "工资是：" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "美术部门的信息：" << endl;
	multimap<int, Worker>::iterator pos2 = m.find(MEISHU);
	//统计美术部门多少人
	int count2 = m.count(MEISHU);
	int index2 = 0;
	for (;pos2!=m.end() && index2 <count2;pos2++,index2++)
	{
		cout << "姓名是：" << pos2->second.m_Name << "工资是：" << pos2->second.m_Salary << endl;
	}
	cout << endl;

	cout << "研发部门的信息：" << endl;
	multimap<int, Worker>::iterator pos3 = m.find(YANFA);
	//统计美术部门多少人
	int count3 = m.count(YANFA);
	int index3 = 0;
	for (; pos3 != m.end() && index3 < count3; pos3++, index3++)
	{
		cout << "姓名是：" << pos3->second.m_Name << "工资是：" << pos3->second.m_Salary << endl;
	}



}
int main() {
	//创建员工
	vector<Worker>vWorker;

	createWorker(vWorker);

	//测试
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
		cout << it->m_Name << "的薪资是" << it->m_Salary << endl;
	}*/

	//员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	
	//分组显示员工
	showWorkerByGroup(mWorker);


	system("pause");
	return 0;

}
