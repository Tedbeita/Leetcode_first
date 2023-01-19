#pragma once
#include <iostream>
using namespace std;
#include <string>

//职工类抽象
class Worker
{
public:

	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门
	int m_DeptId;
	//显示个人信息
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0; 
};