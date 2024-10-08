#include"manager.h"

//构造函数
Manager::Manager(int id,string name,int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示员工信息
void Manager::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：承上启下" << endl;
}

//获取岗位名称
string Manager::getDeptName() {
	return "经理";
}