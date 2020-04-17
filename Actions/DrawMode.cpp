#include "DrawMode.h"
#include "..\ApplicationManager.h"
#include"..\Figures\Circle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <ostream>

DrawMode::DrawMode(ApplicationManager * pApp):Action(pApp)
{
}
void DrawMode::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action: Switched to Draw Mode");
	pOut->CreateDrawToolBar();
	pManager->RemoveAll();
	ifstream load;
	load.open("Saved//drawingsaved.txt", ios::in);
	int countofsave;
	load >> countofsave;
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
	pManager->UpdateInterface();
}
void DrawMode::Execute()
{
	ReadActionParameters();
}

DrawMode::~DrawMode(void)
{
	delete pManager;
}
