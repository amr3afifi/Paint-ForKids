#include "ChangeDrawclr.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawclr::ChangeDrawclr(ApplicationManager * pApp) :Action(pApp)
{
}

void ChangeDrawclr::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Change Draw color , Choose Color");
	pOut->PrintMessage("Choose Draw Color");
	ActionType dcolor = pManager->GetUserAction();
	if (pManager->GetSelected() != NULL)
	{
		switch (dcolor)
		{
		case rED:
			pManager->GetSelected()->ChngDrawClr(RED);
			pOut->PrintMessage("Shape Draw Color: Red is Selected");
			break;
		case bLUE:
			pManager->GetSelected()->ChngDrawClr(BLUE);
			pOut->PrintMessage("Shape Draw Color: Blue is Selected");
			break;
		case gREEN:
			pManager->GetSelected()->ChngDrawClr(GREEN);
			pOut->PrintMessage("Shape Draw Color: Green is Selected");
			break;
		case wHITE:
			pManager->GetSelected()->ChngDrawClr(WHITE);
			pOut->PrintMessage("Shape Draw Color: White is Selected");
			break;
		case oRANGE:
			pManager->GetSelected()->ChngDrawClr(ORANGE);
			pOut->PrintMessage("Shape Draw Color: Orange is Selected");
			break;
		case bLACK:
			pManager->GetSelected()->ChngDrawClr(BLACK);
			pOut->PrintMessage("Shape Draw Color: Black is Selected");
			break;
		default: pOut->PrintMessage("No Shape draw color is selected,Repeat Action");
		}
	}
	else
	{
		switch (dcolor)
		{
		case rED:
			UI.DrawColor = RED;
			pOut->PrintMessage("UI Draw Color: Red is Selected");
			break;
		case bLUE:
			UI.DrawColor = BLUE;
			pOut->PrintMessage("UI Draw Color: Blue is Selected");
			break;
		case gREEN:
			UI.DrawColor = GREEN;
			pOut->PrintMessage("UI Draw Color: Green is Selected");
			break;
		case wHITE:
			UI.DrawColor = WHITE;
			pOut->PrintMessage("UI Draw Color: White is Selected");
			break;
		case oRANGE:
			UI.DrawColor = ORANGE;
			pOut->PrintMessage("UI Draw Color: Orange is Selected");
			break;
		case bLACK:
			UI.DrawColor = BLACK;
			pOut->PrintMessage("UI Draw Color: Black is Selected");
			break;

		default: pOut->PrintMessage("No UI draw color is selected,Repeat Action");
		}
	}
}

void ChangeDrawclr::Execute()
{
	ReadActionParameters();
}

ChangeDrawclr::~ChangeDrawclr()
{
	delete pManager;
}

