#include "CopyAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp)
{
}

void CopyAction::ReadActionParameters(){
	Output*pOut = pManager->GetOutput();
	if(pManager->GetSelected()!=NULL)
	{
		pOut->PrintMessage("Action: Copy");
		CFigure*ptr = pManager->GetSelected();
	    pManager->SetClipboard(ptr);
	}
	else
	{
		pOut->PrintMessage("Select a Figure First");
	}
}

void CopyAction::Execute()
{
	ReadActionParameters();
}

CopyAction::~CopyAction()
{
	delete pManager;
}
