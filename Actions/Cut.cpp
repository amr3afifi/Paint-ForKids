#include "Cut.h"
#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Cut::Cut(ApplicationManager * pApp) :Action(pApp)
{
}

void Cut::ReadActionParameters(){
	Output*pOut = pManager->GetOutput();
	if(pManager->GetSelected()!=NULL)
	{
		  pOut->PrintMessage("Action : Cut ");
		  CFigure*ptr = pManager->GetSelected();
	      pManager->SetClipboard(ptr);
		  pManager->RemoveFigure();
	}
	else
	{
		pOut->PrintMessage("Choose a Figure to Cut");
	}
}

void Cut::Execute()
{
	ReadActionParameters();
}

Cut::~Cut(void)
{
	delete pManager;
}
