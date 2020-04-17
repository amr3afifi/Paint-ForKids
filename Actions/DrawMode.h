#pragma once
#include "action.h"

class DrawMode :public Action
{
public:
	DrawMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DrawMode();
};

