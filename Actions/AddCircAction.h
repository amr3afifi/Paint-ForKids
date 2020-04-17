#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#pragma once
#include "Action.h"

class AddCircAction :
	public Action
{
private:
	Point P1, P2; //Circle Points
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();
	~AddCircAction();
};

#endif