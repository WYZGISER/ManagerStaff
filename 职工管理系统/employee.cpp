#include "employee.h"


//���캯��
Employee::Employee(int id, string name, int dit) {
	//�Ѱ���������Խ��г�ʼ��
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dit;
}

//��ʾ������Ϣ
void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
	/*cout << "ְ��������" << this->m_Name << endl;
	cout << "���ű��" << this->m_DeptId << endl;*/


}

//��ȡԱ����λ����
string Employee::getDeptName(){
	return string("Ա��");
}