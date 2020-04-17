#include "PickAndHideColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include"..\Figures\Circle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"
#include"..\Figures\CFigure.h"
#include "action.h"
#include <cstdlib>
#include <MMSystem.h>
#include <fstream>
#include <ostream>

PickAndHideColor::PickAndHideColor(ApplicationManager * pApp):Action(pApp)
{
	right=0;
	all=0;
	Colors=NULL;
}

void PickAndHideColor::ReadActionParameters()
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
		m=rand()%6;
	if(m==0)
	{
		Colors=RED;
	}
	else if(m==1)
	{
		Colors=BLUE;
	}
	else if(m==2)
	{
		Colors=WHITE;
	}
	else if(m==3)
	{
		Colors=GREEN;
	}
	else if(m==4)
	{
		Colors=ORANGE;
	}
	else
	{
		Colors=BLACK;
	}
	bool f=pManager->CheckColor(Colors);
	if(f)
	{
		break;
	}
	} 
	if(m==0)
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color Red");
	}
	else if(m==1)
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color Blue");
	}
	else if(m==2)
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color White");
	}
	else if(m==3)
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color Green");
	}
	else if(m==4)
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color Orange");
	}
	else
	{
		pOut->PrintMessage("Action:Pick and Hide Color Game, Choose Figures with the color Black ");
	}
	int a=pManager->CountFigures(Colors);
	while(a>0)
	{
		Point p1;
		pIn->GetPointClicked(p1.x,p1.y);
		CFigure*c=pManager->GetFigure(p1.x,p1.y);
		if(c!=NULL)
		{
			all++;
			if(c->figtype()=="l")
			{
				c->ChngFillClr(c->ReturnDrawClr());
			}
			if(c->ReturnFillClr()==Colors)
			{
				right++;
				a--;
				pOut->PrintMessage("Good Job!,CONTINUE");
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
void PickAndHideColor::Execute() 
{
	ReadActionParameters();
}

PickAndHideColor::~PickAndHideColor()
{
	delete pManager;
}
