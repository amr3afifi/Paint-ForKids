#include "PickAndHideBoth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "action.h"
#include"..\Figures\Circle.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\Line.h"
#include"..\Figures\Triangle.h"
#include"..\Figures\CFigure.h"
#include <cstdlib>
#include <MMSystem.h>
#include"..\Figures\CFigure.h"
#include <fstream>
#include <ostream>


PickAndHideBoth::PickAndHideBoth(ApplicationManager * pApp):Action(pApp)
{
	right=0;
	all=0;
	Colors=NULL;
}
void PickAndHideBoth::ReadActionParameters()
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
		m=rand()%7;
		v=rand()%7;
	if(m==0 && v==0)
	{
		C=new CRectangle; Colors=RED;
	}
	else if(m==0 && v==1)
	{
		C=new CRectangle; Colors=BLUE;
	}
	else if(m==0 && v==2)
	{
		C=new CRectangle; Colors=WHITE;
	}
	else if(m==0 && v==3)
	{
		C=new CRectangle; Colors=GREEN;
	}
	else if(m==0 && v==4)
	{
		C=new CRectangle; Colors=ORANGE;
	}
	else if(m==0 && v>4)
	{
		C=new CRectangle; Colors=BLACK;
	}
	else if(m==1 && v==0)
	{
		C=new CCircle; Colors=RED;
	}
	else if(m==1 && v==1)
	{
		C=new CCircle; Colors=BLUE;
	}
	else if(m==1 && v==2)
	{
		C=new CCircle; Colors=WHITE;
	}
	else if(m==1 && v==3)
	{
		C=new CCircle; Colors=GREEN;
	}
	else if(m==1 && v==4)
	{
		C=new CCircle; Colors=ORANGE;
	}
	else if(m==1 && v>4)
	{
		C=new CCircle; Colors=BLACK;
	}
	else if(m==2 && v==0)
	{
		C=new CLine; Colors=RED;
	}
	else if(m==2 && v==1)
	{
		C=new CLine; Colors=BLUE;
	}
	else if(m==2 && v==2)
	{
		C=new CLine; Colors=WHITE;
	}
	else if(m==2 && v==3)
	{
		C=new CLine; Colors=GREEN;
	}
	else if(m==2 && v==4)
	{
		C=new CLine; Colors=ORANGE;
	}
	else if(m==2 && v>4)
	{
		C=new CLine; Colors=BLACK;
	}
	else if(m>2 && v==0)
	{
		C=new Triangle; Colors=RED;
	}
	else if(m>2 && v==1)
	{
		C=new Triangle; Colors=BLUE;
	}
	else if(m>2 && v==2)
	{
		C=new Triangle; Colors=WHITE;
	}
	else if(m>2 && v==3)
	{
		C=new Triangle; Colors=GREEN;
	}
	else if(m>2 && v==4)
	{
		C=new Triangle; Colors=ORANGE;
	}
	else if(m>2 && v>4)
	{
		C=new Triangle; Colors=BLACK;
	}
	bool f=(pManager->CheckBoth(C,Colors));
	if(f)
	{
		break;
	}
	}
	if(m==0 && v==0)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Red Rectangle Figures");
	}
	else if(m==0 && v==1)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Blue Rectangle Figures");
	}
	else if(m==0 && v==2)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose White Rectangle Figures");
	}
	else if(m==0 && v==3)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Green Rectangle Figures");
	}
	else if(m==0 && v==4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Orange Rectangle Figures");
	}
	else if(m==0 && v==5)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Black Rectangle Figures");
	}
	else if(m==1 && v==0)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Red Circle Figures");
	}
	else if(m==1 && v==1)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Blue Circle Figures");
	}
	else if(m==1 && v==2)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose White Circle Figures");
	}
	else if(m==1 && v==3)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Green Circle Figures");
	}
	else if(m==1 && v==4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Orange Circle Figures");
	}
	else if(m==1 && v>4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Black Circle Figures");
	}
	else if(m==2 && v==0)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Red Line Figures");
	}
	else if(m==2 && v==1)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Blue Line Figures");
	}
	else if(m==2 && v==2)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose White Line Figures");
	}
	else if(m==2 && v==3)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Green Line Figures");
	}
	else if(m==2 && v==4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Orange Line Figures");
	}
	else if(m==2 && v>4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Black Line Figures");
	}
	else if(m>2 && v==0)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Red Triangle Figures");
	}
	else if(m>2 && v==1)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Blue Triangle Figures");
	}
	else if(m>2 && v==2)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose White Triangle Figures");
	}
	else if(m>2 && v==3)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Green Triangle Figures");
	}
	else if(m>2 && v==4)
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Orange Triangle Figures");
	}
	else if(m>2 && v>4)  
	{
		pOut->PrintMessage("Action:Pick and Hide type Game, Choose Black Triangle Figures");
	}
	int a=pManager->CountFigures(C,Colors);
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
			if(c->ReturnFillClr()==Colors && c->isEqual(C))
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
void PickAndHideBoth::Execute()
{
	ReadActionParameters();
}
PickAndHideBoth::~PickAndHideBoth(void)
{
	delete C;
	delete pManager;
}
