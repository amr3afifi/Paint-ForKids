#include "PlayMode.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <ostream>

PlayMode::PlayMode(ApplicationManager * pApp):Action(pApp)
{
}
void PlayMode::ReadActionParameters()
{
}
void PlayMode::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action: Switched to Play Mode");
	pOut->CreatePlayToolBar();
	ofstream save;
	save.open("Saved//drawingsaved.txt", ios::out);
	save << pManager->getfigcountappmanager() + 1;
	save << endl;
	pManager->SaveAll(save);
	save.close();
}
PlayMode::~PlayMode()
{
	delete pManager;
}
