#pragma once
#include "action.h"

class AddLineAction :public Action
{
	Point P1, P2; //Line Corners
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);
	//Reads Line parameters
	virtual void ReadActionParameters();
	
	//Add Line to the ApplicationManager
	virtual void Execute() ;
	
	~AddLineAction();
};

