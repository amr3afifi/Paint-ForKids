#include "AddTriAction.h"
#include "..\Figures\Triangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp) :Action(pApp)
{
}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at a point");

	//Read and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y>(UI.height - UI.StatusBarHeight) || P1.y < UI.ToolBarHeight)
	{
		pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	pOut->PrintMessage("New Triangle: Click at the second point");

	//Read and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while (P2.y>(UI.height - UI.StatusBarHeight) || P2.y < UI.ToolBarHeight)
	{
		pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
		pIn->GetPointClicked(P2.x, P2.y);
	}

	pOut->PrintMessage("New Triangle: Click at the third point");

	//Read and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	while (P3.y>(UI.height - UI.StatusBarHeight) || P3.y < UI.ToolBarHeight)
	{
		pOut->PrintMessage("You chose an invalid location re-enter habiby Please");
		pIn->GetPointClicked(P3.x, P3.y);
	}

	TriGfxInfo.isFilled = false;	//default is not filled
	if(UI.IsFilled)
	{
		TriGfxInfo.isFilled = true;
	}
	//get drawing, filling colors and pen width from the interface

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	Triangle *R=new Triangle(P1, P2,P3,TriGfxInfo);

	R->SetID(pManager->getfigcountappmanager() + 1);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
}

AddTriAction::~AddTriAction()
{
	delete pManager;
}