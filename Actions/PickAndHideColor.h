#pragma once
#include "action.h"
class PickAndHideColor :public Action
{
	int m;
	int right;
	int all;
	color Colors;
public:
	PickAndHideColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PickAndHideColor();
};

