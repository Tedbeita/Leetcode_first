#pragma once	//防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"


class WorkerManager {
public:

	WorkerManager();

	void Show_Menu();

	void ExitSystem();
	//添加职工
	void Add_Emp();

	void save();

	//判断职工是否为空的标志
	bool FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	void show_Emp();

	void Del_Emp();

	int IsExist(int id);

	void modify_Emp();

	void find_Emp();

	//排序
	void sort();

	void cleanFile();

	~WorkerManager();




	//职工数组指针
	Worker** m_EmpArray;
	//职工人数
	int m_EmpNum;


};
