#include "ChngBordWdthAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngBordWdthAction::ChngBordWdthAction(ApplicationManager * pApp) :Action(pApp)
{
}

void ChngBordWdthAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Change BorderWidth ,Each Color provides a width->Red(1),Black(2),Blue(3),Orange(4),White(5),Green(6)");
	ActionType dcolor = pManager->GetUserAction();
	if (pManager->GetSelected() != NULL)
	{
		switch (dcolor)
		{
		case rED:
			pManager->GetSelected()->ChngBordWdth(2);
			pOut->PrintMessage("Border Width 1 is applied");
			break;
		case bLUE:
			pManager->GetSelected()->ChngBordWdth(6);
			pOut->PrintMessage("Border Width 3 is applied");
			break;
		case gREEN:
			pManager->GetSelected()->ChngBordWdth(12);
			pOut->PrintMessage("Border Width 6 is applied");
			break;
		case wHITE:
			pManager->GetSelected()->ChngBordWdth(10);
			pOut->PrintMessage("Border Width 5 is applied");
			break;
		case oRANGE:
			pManager->GetSelected()->ChngBordWdth(8);
			pOut->PrintMessage("Border Width 4 is applied");
			break;
		case bLACK:
			pManager->GetSelected()->ChngBordWdth(4);
			pOut->PrintMessage("Border Width 2 is applied");
			break;
		default: pOut->PrintMessage("NO Border Width selected,Repeat Action");
		}

	}
	else
	{
		switch (dcolor)
		{
		case rED:
			UI.PenWidth = 2;
			pOut->PrintMessage("UI Border Width 1 is applied");
			break;
		case bLUE:
			UI.PenWidth = 6;
			pOut->PrintMessage("UI Border Width 3 is applied");
			break;
		case gREEN:
			UI.PenWidth = 12;
			pOut->PrintMessage("UI Border Width 6 is applied");
			break;
		case wHITE:
			UI.PenWidth = 10;
			pOut->PrintMessage("UI Border Width 5 is applied");
			break;
		case oRANGE:
			UI.PenWidth = 8;
			pOut->PrintMessage("UI Border Width 4 is applied");
			break;
		case bLACK:
			UI.PenWidth = 4;
			pOut->PrintMessage("UI Border Width 2 is applied");
			break;

		default: pOut->PrintMessage("No Border Width is applied,Repeat Action");
		}
	}
}

void ChngBordWdthAction::Execute()
{
	ReadActionParameters();
}

ChngBordWdthAction::~ChngBordWdthAction()
{
}
