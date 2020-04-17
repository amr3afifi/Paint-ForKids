#pragma once
#include "Action.h"
class ChngBordWdthAction :
	public Action
{
public:
	ChngBordWdthAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ChngBordWdthAction();
};

