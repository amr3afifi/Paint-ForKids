#pragma once
#include "Action.h"

class Select :public Action
{
	Point P1;
public:
	Select(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Select(void);
};

