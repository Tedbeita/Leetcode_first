#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Manager : public Worker
{
public:
	Manager (int Id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};