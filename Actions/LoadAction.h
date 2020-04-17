#pragma once
#include "Action.h"
class LoadAction :
	public Action
{
	string filename;
public:
	LoadAction(ApplicationManager * pApp);
	void Execute();
	void ReadActionParameters();
	~LoadAction();
};

