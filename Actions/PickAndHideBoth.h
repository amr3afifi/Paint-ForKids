#pragma once
#include "action.h"
#include "..\Figures\CFigure.h"

class PickAndHideBoth :
	public Action
{
	int m;
	int v;
	int right;
	int all;
	color Colors;
	CFigure*C;
public:
	PickAndHideBoth(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PickAndHideBoth();
};

