#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



Select::Select(ApplicationManager * pApp) :Action(pApp)
{
}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose a Figure");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
	CFigure*C = pManager->GetFigure(P1.x, P1.y);
	if (C != NULL)
	{
		if (C->IsSelected() == false)
		{
			pManager->setselect(C);
			pOut->PrintMessage("Figure Selected");
			C->PrintInfo(pOut);
		}
		else
		{
			pOut->PrintMessage("Figure UnSelected");
			pManager->unselect();

		}
	}
	else  pOut->PrintMessage("No Figure Chosen");
}

void Select::Execute()
{
	ReadActionParameters();
}


Select::~Select()
{
	delete pManager;
}
