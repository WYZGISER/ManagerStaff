#pragma once
#include <iostream>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
using namespace std;

#include<fstream>
#define FILENAME "empFile.txt"


class  WorkerManadger {
public:
	//���캯��
	WorkerManadger();

	//չʾ�˵�����
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ��������
	int m_EmpNum;

	//ְ�������ָ��
	Worker** m_EmpArrzay;

	//���ְ������
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	
	//ͳ����������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();
	
	//����ְ��
	void Find_Emp();
	
	//����ļ�
	void Clean_File();

	//��������
	~WorkerManadger();
};
