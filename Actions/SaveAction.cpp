#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <ostream>

SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Action Save: Enter file name");
	FileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();

}

void SaveAction::Execute()
{
	ReadActionParameters();
	
	ofstream OutFile;
	OutFile.open("Saved//" + FileName + ".txt", ios::out);
	if (UI.DrawColor == ORANGE)
		OutFile << "ORANGE" << endl;
	if (UI.DrawColor == WHITE)
		OutFile << "WHITE" << endl;
	if (UI.DrawColor == BLACK)
		OutFile << "BLACK" << endl;

	if (UI.DrawColor == BLUE)
		OutFile << "BLUE" << endl;

	if (UI.DrawColor == RED)
		OutFile << "RED" << endl;

	if (UI.DrawColor == GREEN)
		OutFile << "GREEN" << endl;

	if (UI.FillColor == ORANGE)
		OutFile << "ORANGE" << endl;

	if (UI.FillColor == BLACK)
		OutFile << "BLACK" << endl;

	if (UI.FillColor == BLUE)
		OutFile << "BLUE" << endl;

	if (UI.FillColor == RED)
		OutFile << "RED" << endl;

	if (UI.FillColor == WHITE)
		OutFile << "WHITE" << endl;

	if (UI.FillColor == GREEN)
		OutFile << "GREEN" << endl;

	OutFile << pManager->getfigcountappmanager() + 1;
	OutFile << endl;
	pManager->SaveAll(OutFile); 
	OutFile.close();
}

SaveAction::~SaveAction()
{
	delete pManager;
}
