#include "Exit.h"
#include "action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SaveAction.h"

Exit::Exit(ApplicationManager * pApp):Action(pApp)
{
}
void Exit::ReadActionParameters()
{
}
void Exit::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Your Current Graph will be lost if you proceed , click save icon to save or click anywhere else to proceed");
	ActionType app = pManager->GetUserAction();
	if (app == ITM_SAVE) {
		Action* action = new SaveAction(pManager);
		action->Execute();
	}
 return;
}
Exit::~Exit()
{
	delete pManager;
}
