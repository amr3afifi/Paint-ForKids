#include "Resize.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\ApplicationManager.h"
#include<string>

Resize::Resize(ApplicationManager*pApp):Action(pApp)
{
}

void Resize::ReadActionParameters()
{
	Input*pIn = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Resize a Figure....Write(q)->quarter,(h)->half,(d)->double,(qu)->quadrible");
	string S=pIn->GetSrting(pOut);
	pManager->resize(S);
	
}

void Resize::Execute()
{
	ReadActionParameters();


}

Resize::~Resize(void)
{
	delete pManager;
}
