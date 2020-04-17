#pragma once
#include "action.h"

class ChangeFillClr :public Action
{
public:
	ChangeFillClr(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChangeFillClr(void);
};

