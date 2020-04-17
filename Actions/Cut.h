#pragma once
#include "action.h"
#include "CopyAction.h"
class Cut :
	public Action
{
public:
	Cut(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};

