#pragma once
#include "Action.h"
class PasteAction :
	public Action
{
	Point p1;
public:
	PasteAction();
	PasteAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PasteAction();
};

