#include "LoadAction.h"
#include "..\Figures\Circle.h"
#include "..\Figures\Line.h"
#include "..\Figures\Triangle.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SaveAction.h"
#include <fstream>
#include <iostream>

LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
		pOut->PrintMessage("Your Current Graph will be lost if you proceed , click save icon to save or click anywhere else to proceed");
		ActionType app = pManager->GetUserAction();
		if (app == ITM_SAVE) {
			Action* action = new SaveAction(pManager);
			action->Execute();
		}
	pOut->PrintMessage("Specify the name of the file you want to load from:  ");
	filename = pIn->GetSrting(pOut);
}

void LoadAction::Execute(){
	ifstream load;
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	load.open("Saved//" + filename + ".txt", ios::in);
	if (!load) {
		pOut->PrintMessage("File Not Found");
		return;
	}
	pManager->RemoveAll();
	pOut->ClearStatusBar();
	string drwclr;
	load >> drwclr;
	if (drwclr == "ORANGE")
		UI.DrawColor = ORANGE;
	if (drwclr == "WHITE")
		UI.DrawColor = WHITE;
	if (drwclr == "BLACK")
		UI.DrawColor = BLACK;
	if (drwclr == "BLUE")
		UI.DrawColor = BLUE;
	if (drwclr == "RED")
		UI.DrawColor = RED;
	if (drwclr == "GREEN")
		UI.DrawColor = GREEN;
	string fillclr;
	load >> fillclr;
	if (fillclr == "ORANGE")
		UI.FillColor = ORANGE;
	if (fillclr == "BLACK")
		UI.FillColor = BLACK;
	if (fillclr == "BLUE")
		UI.FillColor = BLUE;
	if (fillclr == "RED")
		UI.FillColor = RED;
	if (fillclr == "GREEN")
		UI.FillColor = GREEN;
	if (fillclr == "WHITE")
		UI.FillColor = WHITE;
	int countofsave;
	load >> countofsave;
	//for (int i = 0; i < countofsave;i++)
	while (!load.eof())
	{
		string FigType;
		load >> FigType;
		if (FigType == "Rectangle")
		{
			CRectangle* rec = new CRectangle;
			rec->Load(load);
			pManager->AddFigure(rec);
		}
		if (FigType == "Triangle")
		{
			Triangle* trig = new Triangle;
			trig->Load(load);
			pManager->AddFigure(trig);
		}
		if (FigType == "Circle")
		{
			CCircle* circ = new CCircle;
			circ->Load(load);
			pManager->AddFigure(circ);
		}
		if (FigType == "Line")
		{
			CLine * line = new CLine;
			line->Load(load);
			pManager->AddFigure(line);
		}
	}
load.close();
}

LoadAction::~LoadAction()
{
	delete pManager;
}
