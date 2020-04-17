#pragma once
#pragma once
#include "Action.h"

class ROtateAction :
	public Action
{
public:
	ROtateAction(ApplicationManager*pApp);
	void ReadActionParameters();
	void Execute();
	~ROtateAction(void);
};
