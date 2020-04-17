#pragma once
#include "action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
class Exit :public Action
{
public:
	Exit(ApplicationManager *pApp);
	virtual void Execute() ;
	virtual void ReadActionParameters();
	~Exit();
};

