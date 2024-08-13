#include "employee.h"


//构造函数
Employee::Employee(int id, string name, int dit) {
	//把把自身的属性进行初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dit;
}

//显示个人信息
void Employee::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
	/*cout << "职工姓名：" << this->m_Name << endl;
	cout << "部门编号" << this->m_DeptId << endl;*/


}

//获取员工岗位名称
string Employee::getDeptName(){
	return string("员工");
}