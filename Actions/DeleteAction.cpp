#include "DeleteAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	if (pManager->GetSelected() != NULL)
	{
		pOut->PrintMessage("Action : Deleted selected figure ");
		pManager->RemoveFigure();
	}
	else
	{
		pOut->PrintMessage("Choose a Figure to Delete");
	}
}

void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->RemoveFigure();
}

DeleteAction::~DeleteAction()
{
	delete pManager;
}
