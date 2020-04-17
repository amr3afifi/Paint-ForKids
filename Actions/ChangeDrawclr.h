#pragma once
#include "action.h"

class ChangeDrawclr :public Action
{
public:
	ChangeDrawclr(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChangeDrawclr();
};

