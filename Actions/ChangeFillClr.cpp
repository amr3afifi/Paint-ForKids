#include "ChangeFillClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillClr::ChangeFillClr(ApplicationManager * pApp) :Action(pApp)
{
}

void ChangeFillClr::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Change Fill color , Choose Color");
	pOut->PrintMessage("Choose Fill Color");
	ActionType dcolor = pManager->GetUserAction();
	if (pManager->GetSelected() != NULL)
	{
		switch (dcolor)
		{
		case rED:
			pManager->GetSelected()->ChngFillClr(RED);
			pOut->PrintMessage("Shape Fill Color: Red is Selected");
			break;
		case bLUE:
			pManager->GetSelected()->ChngFillClr(BLUE);
			pOut->PrintMessage("Shape Fill Color: Blue is Selected");
			break;
		case gREEN:
			pManager->GetSelected()->ChngFillClr(GREEN);
			pOut->PrintMessage("Shape Fill Color: Green is Selected");
			break;
		case wHITE:
			pManager->GetSelected()->ChngFillClr(WHITE);
			pOut->PrintMessage("Shape Fill Color: White is Selected");
			break;
		case oRANGE:
			pManager->GetSelected()->ChngFillClr(ORANGE);
			pOut->PrintMessage("Shape Fill Color: Orange is Selected");
			break;
		case bLACK:
			pManager->GetSelected()->ChngFillClr(BLACK);
			pOut->PrintMessage("Shape Fill Color: Black is Selected");
			break;
		default: pOut->PrintMessage("No Shape Fill Color is selected,Repeat Action");
		}
	}
	else
	{
		UI.IsFilled = true;
		switch (dcolor)
		{
		case rED:
			UI.FillColor = RED;
			pOut->PrintMessage("UI Fill Color: Red is Selected");
			break;
		case bLUE:
			UI.FillColor = BLUE;
			pOut->PrintMessage("UI Fill Color: Blue is Selected");
			break;
		case gREEN:
			UI.FillColor = GREEN;
			pOut->PrintMessage("UI Fill Color: Green is Selected");
			break;
		case wHITE:
			UI.FillColor = WHITE;
			pOut->PrintMessage("UI Fill Color: White is Selected");
			break;
		case oRANGE:
			UI.FillColor = ORANGE;
			pOut->PrintMessage("UI Fill Color: Orange is Selected");
			break;
		case bLACK:
			UI.FillColor = BLACK;
			pOut->PrintMessage("UI Fill Color: Black is Selected");
			break;

		default: pOut->PrintMessage("No UI Fill Color is selected,Repeat Action");
		}
	}
}

void ChangeFillClr::Execute()
{
	ReadActionParameters();
}

ChangeFillClr::~ChangeFillClr()
{
		delete pManager;
}