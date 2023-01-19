#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{

	//实例化管理者对象
	WorkerManager wm;
	//调用展示菜单成员函数

	int choice = 0;//用来存储用户选择
	
	while (true)
	{
		//调用成员菜单函数
		wm.Show_Menu();

		cout << "请输入您的选择" << endl;
		cin >> choice;	//接收用户的选项

		switch (choice)
		{
		case 0:		//退出系统
			wm.ExitSystem();
			break;
		case 1:		//增加职工
			wm.Add_Emp();
			break;
		case 2:		//显示职工
			wm.show_Emp();
			break;
		case 3:		//删除职工
			wm.Del_Emp();
			break;
		case 4:		//修改职工
			wm.modify_Emp();
			break;
		case 5:		//查找职工
			wm.find_Emp();
			break;
		case 6:		//排序职工
			wm.sort();
			break;
		case 7:		//清空文档
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}

	}


	system("pause");
	
	return 0; 

}