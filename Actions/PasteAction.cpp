#include "PasteAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "CopyAction.h"
#include "..\Figures\Line.h"
#include "..\Figures\Circle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\Triangle.h"

#include "Select.h"

PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Input* pIn=pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if(pManager->GetClipboard()!=NULL)
	{
		pOut->PrintMessage("Action paste: paste figure in Clipboard");
		pIn->GetPointClicked(p1.x, p1.y);
		CFigure* yala = pManager->GetClipboard()->paste(p1.x, p1.y);
		pManager->AddFigure(yala);
	}
	else
	{
		pOut->PrintMessage("Copy or Cut a Figure First");
	}
}

void PasteAction::Execute()
{
	ReadActionParameters();
}

PasteAction::~PasteAction()
{
	delete pManager;
}