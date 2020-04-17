#pragma once
#include "action.h"

class Resize :
	public Action
{
public:
	Resize(ApplicationManager*pApp);
	void ReadActionParameters();
	void Execute();
	~Resize(void);
};

