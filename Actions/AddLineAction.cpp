#include "AddLineAction.h"
#include "..\Figures\Line.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y>(UI.height - UI.StatusBarHeight) || P1.y < UI.ToolBarHeight)
	{
		pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while (P2.y>(UI.height - UI.StatusBarHeight) || P2.y < UI.ToolBarHeight)
	{
		pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	

   //Create a Line with the parameters read from the user
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	R->SetID(pManager->getfigcountappmanager() + 1);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}

AddLineAction::~AddLineAction()
{
	delete pManager;
}