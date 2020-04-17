#include "Pickandhidetype.h"
#include "..\ApplicationManager.h"
#include"..\Figures\Circle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"
#include"..\Figures\CFigure.h"
#include "Action.h"
#include<Windows.h>
#include<ctime>
#include <fstream>
#include <ostream>

using namespace std;
Pickandhidetype::Pickandhidetype(ApplicationManager*pApp):Action(pApp)
{
   C=NULL;
   all=0;
   right=0;
}

void Pickandhidetype::ReadActionParameters()
{
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
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
	while(1)
	{
	m=rand()%4;
	if(m==0)
	{
		C=new CRectangle;
	}
	else if(m==1)
	{
		C=new CCircle;
	}
	else if(m==2)
	{
		C=new CLine;
	}
	else 
	{
		C=new Triangle;
	}
	bool f=pManager->CheckType(C);
	if(f)
	{
		break;
	}
	} 
	if(m==0)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Rectangle Figures");
	}
	else if(m==1)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Circle Figures");
	}
	else if(m==2)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Line Figures");
	}
	else if(m==3)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Triangle Figures");
	}
	
	int a=pManager->CountFigures(C);
	while(a>0)
	{
		Point p1;
		pIn->GetPointClicked(p1.x,p1.y);
		CFigure*c=pManager->GetFigure(p1.x,p1.y);
		if(c!=NULL)
		{
			all++;
			if(c->isEqual(C))
			{
				right++;
				a--;
				pOut->PrintMessage("Good Job!, Continue");
				pManager->setselect(c);
				pManager->RemoveFigure();
				pManager->UpdateInterface();
			}
			else
			{
	            
				pOut->PrintMessage("Wroooong!! :( ");
			}
		}
		else
		{
			pOut->PrintMessage("Choose a Figure!!");
		}

	}
	pOut->PrintMessage("");
	pOut->PrintScore("You Won!! your score is ",right,"/ ",all);
	PlaySound(TEXT("TaDa.wav"), NULL, SND_SYNC);
}



void Pickandhidetype::Execute()
{
	ReadActionParameters();
}
Pickandhidetype::~Pickandhidetype()
{
	delete C;
	delete pManager;
}
