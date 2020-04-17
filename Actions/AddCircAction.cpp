#include "AddCircAction.h"
#include "..\Figures\Circle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager * pApp) :Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
//Get a Pointer to the Input / Output Interfaces
Output* pOut = pManager->GetOutput();
Input* pIn = pManager->GetInput();

pOut->PrintMessage("New Cirlce: Click at center");

//Read and store in point P1
pIn->GetPointClicked(P1.x, P1.y);
while (P1.y>(UI.height - UI.StatusBarHeight) || P1.y < UI.ToolBarHeight)
{
	pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
	pIn->GetPointClicked(P1.x, P1.y);
}

pOut->PrintMessage("New Circle: Click at another point");

//Read and store in point P2
pIn->GetPointClicked(P2.x, P2.y);
while (P2.y>(UI.height - UI.StatusBarHeight) || P2.y < UI.ToolBarHeight)
{
	pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
	pIn->GetPointClicked(P2.x, P2.y);
}

CircGfxInfo.isFilled = false;	//default is not filled
if(UI.IsFilled)
	{
		CircGfxInfo.isFilled = true;
	}
//get drawing, filling colors and pen width from the interface
CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
CircGfxInfo.FillClr = pOut->getCrntFillColor();
CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

pOut->ClearStatusBar();
}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	//Create a Circle with the parameters read from the user
	CCircle *R=new CCircle(P1, P2, CircGfxInfo);
	R->SetID(pManager->getfigcountappmanager() + 1);

	//Add the Circle to the list of figures
	pManager->AddFigure(R);
}

AddCircAction::~AddCircAction()
{
	delete pManager;
}

