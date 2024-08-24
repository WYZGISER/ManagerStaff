#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

//��������
//��˾������Ƹ10��Ա����ABCDEFGHIJ����10��Ա�����빫˾����Ҫָ��Ա�����ĸ����Ź���
//Ա����Ϣ�У����� ������ɣ����ŷ�Ϊ�߻� ���� �з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��� key�����ű�ţ�--- value��Ա����
//�ֲ�����ʾԱ����Ϣ
//
//ʵ�ֲ���
//1������10��Ա�����ŵ�vector��
//2������vector������ȡ��ÿ��Ա���������������
//3������󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue���ŵ�multimap������
//4���ֲ�����ʾԱ����Ϣ


class Worker {
public:
	string m_Name;
	int m_Salary;
};

//����Ա������
void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999
		//��Ա���Ž�������
		v.push_back(worker);
	}
}

//Ա�����麯��
void setGroup(vector<Worker> &v,multimap<int,Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {

		//����һ��������ŵı��
		int deptId = rand() % 3;//����0��1��2�������
		
		//��Ա�����������
		m.insert(make_pair(deptId, *it));

		for (multimap<int, Worker>::iterator mit = m.begin(); mit != m.end(); mit++) {

		}
	}
}

//������ʾԱ��
void showWorkerByGroup(multimap<int, Worker>& m) {

	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	cout << "�߻����ŵ���Ϣ��" << endl;
	//ͳ�Ʋ߻����Ŷ�����
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "�����ǣ�" << pos->second.m_Name << "�����ǣ�" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "�������ŵ���Ϣ��" << endl;
	multimap<int, Worker>::iterator pos2 = m.find(MEISHU);
	//ͳ���������Ŷ�����
	int count2 = m.count(MEISHU);
	int index2 = 0;
	for (;pos2!=m.end() && index2 <count2;pos2++,index2++)
	{
		cout << "�����ǣ�" << pos2->second.m_Name << "�����ǣ�" << pos2->second.m_Salary << endl;
	}
	cout << endl;

	cout << "�з����ŵ���Ϣ��" << endl;
	multimap<int, Worker>::iterator pos3 = m.find(YANFA);
	//ͳ���������Ŷ�����
	int count3 = m.count(YANFA);
	int index3 = 0;
	for (; pos3 != m.end() && index3 < count3; pos3++, index3++)
	{
		cout << "�����ǣ�" << pos3->second.m_Name << "�����ǣ�" << pos3->second.m_Salary << endl;
	}



}
int main() {
	//����Ա��
	vector<Worker>vWorker;

	createWorker(vWorker);

	//����
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
		cout << it->m_Name << "��н����" << it->m_Salary << endl;
	}*/

	//Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	
	//������ʾԱ��
	showWorkerByGroup(mWorker);


	system("pause");
	return 0;

}
