#include "ROtateAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ROtateAction::ROtateAction(ApplicationManager *pApp):Action(pApp)
{

}

void ROtateAction::ReadActionParameters()
{
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->PrintMessage("Rotate a Figure");
}

void ROtateAction::Execute()
{
	ReadActionParameters();
	pManager->Rotate();

}

ROtateAction::~ROtateAction(void)
{
	delete pManager;
}

