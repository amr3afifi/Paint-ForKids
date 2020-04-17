#pragma once
#include "action.h"
#include"..\Figures\CFigure.h"

class Pickandhidetype :public Action
{
	int m;
	int right;
	int all;
	CFigure* C;
public:
	Pickandhidetype(ApplicationManager*pApp);
	void ReadActionParameters();
	void Execute();
	~Pickandhidetype();
};

