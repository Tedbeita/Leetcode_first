#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int  i = 0; i <this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "********0.退出管理系统********" << endl;
	cout << "********1.增加职工信息********" << endl;
	cout << "********2.显示职工信息********" << endl;
	cout << "********3.删除离职职工********" << endl;
	cout << "********4.修改职工信息********" << endl;
	cout << "********5.查找职工信息********" << endl;
	cout << "********6.按照编号排序********" << endl;
	cout << "********7.清空所有文档********" << endl;
	cout << "******************************" << endl;

}

//退出系统 
void WorkerManager::ExitSystem()
{
	cout << "欢迎您下次使用" << endl;
	system("pause");
	exit(0); 
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算新空间的大小
		int newSize = this->m_EmpNum + addNum;//新空间等于原来+新增

		//开辟新空间
		Worker** newspace = new Worker * [newSize];

		//将原来的数据拷贝
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dselect;

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
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

			//将创建职工指针保存到数组里
			newspace[this->m_EmpNum + i] = worker;

		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newspace;
		//更改新空间人数
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->FileIsEmpty = false;
		//保存数据
		this->save();
		cout << "成功添加" << addNum << "名新职工" << endl;


		system("pause");
		system("cls");
	}
	else
	{
		//有误
		cout << "数据有误" << endl;
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件
	//写入
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();


}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数变量
		num++;
		 
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if(did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::show_Emp()
{
	//判断文件是否为空
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者你雇不起员工" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();

		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除职工
		cout << "请输入要删除职工的编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中人数
			this->m_EmpNum--;
			//更新到文件里
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "找不到你的对象" << endl;
		}
		

	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;		//找到职工
			break;
		}
	}
	return index; 
}

void WorkerManager::modify_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号修改职工
		cout << "请输入要修改职工的编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			delete this->m_EmpArray[index];

			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "找到你的对象，可以换个对象了" << endl;
			cout << "请输入新的职工编号：" << endl;
			cin >> newid;

			cout << "请输入新的职工姓名：" << endl;
			cin >> newname;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newselect;
			
			Worker* worker = NULL;
			
			switch (newselect)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;

			//更新到文件里
			this->save();

			cout << "修改成功" << endl;
		}
		else
		{
			cout << "找不到你的对象" << endl;
		}

		
	}

	system("pause");
	system("cls");

}

void WorkerManager::find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "空的" << endl;

	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1.编号查找" << endl;
		cout << "2、姓名查找" << endl;

		int select;
		cin >> select;
		if (select == 1)
		{
			//编号查找
			int id;
			cout << "请输入编号" << endl;
			cin >> id;
			
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//找到
				cout << "你有对象了" << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else {
				cout << "找不到对象" << endl;
			}
		}
		else if (select == 2)
		{
			//姓名查找
			string name;
			cout << "请输入查找职工的姓名：" << endl;
			cin >> name;

			//加入一个是否查到的标志
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "找到了，编号是：" << this->m_EmpArray[i]->m_Id << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
  
}

void WorkerManager::sort()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1职工号升序" << endl;
		cout << "2职工号降序" << endl;

		int select = 0;
		int minormax = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i+ 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		
	}

	cout << "排序成功" << endl;
	this->save();
	this->show_Emp();
}

void WorkerManager::cleanFile()
{
	cout << "确定清空？" << endl;
	cout << "1确定" << endl;
	cout << "2返回" << endl;
	
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//删除文件后再重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->FileIsEmpty = true;
			cout << "清空成功" << endl;
		}
	}



	system("pause");
	system("cls");
}