#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\Exit.h"
#include "Actions\ChangeDrawclr.h"
#include "Actions\ChangeFillclr.h"
#include "Actions\PlayMode.h"
#include "Actions\DrawMode.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriAction.h"
#include"Figures\Line.h"
#include <Windows.h>
#include <MMSystem.h>
#include"Actions\Select.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\Cut.h"
#include "Actions\PickAndHideColor.h"
#include "Actions\ChngBordWdthAction.h"
#include "Actions\PickAndHideBoth.h"
#include "Actions\pickandhidetype.h"
#include "Actions\Resize.h"
#include "Actions\ROtateAction.h"
#include <fstream>
#include <ostream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case DRAW_LINE:
			pAct=new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case EXIT:
			pAct=new Exit(this);
			break;

		case CHNG_DRAW_CLR:
			pAct=new ChangeDrawclr(this);
			break;

		case CHNG_FILL_CLR:
			pAct=new ChangeFillClr(this);
			break;

		case TO_PLAY:
			pAct=new PlayMode(this);
			break;

		case TO_DRAW:
			pAct=new DrawMode(this);
			break;
		
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area");
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case ROTATE:
			pAct = new ROtateAction(this);
			break;

		case PICK_HIDE:
			pAct = new PickAndHideColor(this);
			break;

		case PICK_TYPE:
			pAct=new Pickandhidetype(this);
			break;

		case PICK_BOTH:
			pAct=new PickAndHideBoth(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case SELECT:
			pAct=new Select(this);
			break;

		case CUT:
			pAct = new Cut(this);
			break;

		case RESIZE:
			pAct = new Resize(this);
			break;

		case BorderWidth:
			pAct = new ChngBordWdthAction(this);
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

//==================================================================================//
//						Play Mode Functions		            						//
//==================================================================================//

// check color of selected fig in the game matches with required ->if yes return true ->if no return false
bool ApplicationManager::CheckColor(color A)
{
	for(int i=0;i<FigCount;i++)
	{
		if(dynamic_cast<CLine*>(FigList[i]))
		{
			if(FigList[i]->ReturnDrawClr() == A)
		{
			return true;
		}
		}
		else
		{
		if(FigList[i]->ReturnFillClr() == A)
		{
			return true;
		}
		}
	}
	return false;
}
// check type of selected fig in the game matches with required ->if yes return true ->if no return false
bool ApplicationManager::CheckType(CFigure*C)
{
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->isEqual(C))
		{
			return true;
		}
	}
	return false;
}
// check type and color of selected fig in the game matches with required ->if yes return true ->if no return false
bool ApplicationManager::CheckBoth(CFigure*C,color A)
{
	for(int i=0;i<FigCount;i++)
	{
			if(dynamic_cast<CLine*>(FigList[i]))
		{
			if(FigList[i]->ReturnDrawClr() == A && FigList[i]->isEqual(C))
		{
			return true;
		}
		}
		else
		{
		if(FigList[i]->ReturnFillClr() == A && FigList[i]->isEqual(C))
		{
			return true;
		}
		}
	}
	return false;
}
//return count the figures with the required color
int ApplicationManager:: CountFigures(color A)
{
	int k=0;
	for(int i=0;i<FigCount;i++)
	{
			if(dynamic_cast<CLine*>(FigList[i]))
		{
			if(FigList[i]->ReturnDrawClr() == A)
		{
			k++;
		}
		}
		else
		{
		if(FigList[i]->ReturnFillClr() == A)
		{
			k++;
		}
		}
	}
	return k;
}
//return count the figures with the required type
int ApplicationManager:: CountFigures(CFigure*C)
{
	int k=0;
	for(int i=0;i<FigCount;i++)
	{
		if(FigList[i]->isEqual(C))
		{
			k++;
		}
	}
	return k;
}
//return count the figures with the required type and color
int ApplicationManager:: CountFigures(CFigure*C,color A)
{
	int k=0;
		for(int i=0;i<FigCount;i++)
	{
			if(dynamic_cast<CLine*>(FigList[i]))
		{
			if(FigList[i]->ReturnDrawClr() == A && FigList[i]->isEqual(C))
		{
			k++;
		}
		}
		else
		{
		if(FigList[i]->ReturnFillClr() == A && FigList[i]->isEqual(C))
		{
			k++;
		}
		}
	}
	return k;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}

//copy a figure from the list of figures
void ApplicationManager::copyfigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == SelectedFig)
		{
			CFigure*ptr = FigList[i]->copy();
			Clipboard = ptr;
		}
	}
}
//Remove selected figure from the list of Figures
void ApplicationManager::RemoveFigure()
{

	for (int i = 0; i<FigCount; i++)
	{
		if (SelectedFig == FigList[i])
		{
			FigList[i] = NULL;
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
		}
	}
	SelectedFig=NULL;
	pOut->ClearDrawArea();
}
//Remove all figures from the list of figures
void ApplicationManager::RemoveAll()
{
	
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i] = NULL;
	}
	pOut->ClearDrawArea();
	FigCount = 0;
}
//Savee all figures of the list of figures
void ApplicationManager::SaveAll(ofstream &save){
	
	for (int i = 0; i<FigCount; i++){
		FigList[i]->Save(save);
	}
}
//Rotate selected figure from the list of Figures
void ApplicationManager::Rotate()
{
	for (int i = 0; i<FigCount; i++)
	{
		if (SelectedFig == FigList[i])
		{
			pOut->ClearDrawArea();
			FigList[i]->Rotate();
		}
	}
}
//Resize selected figure from the list of Figures
void ApplicationManager::resize(string S)
{

	for (int i = 0; i<FigCount; i++)
	{
		if (SelectedFig == FigList[i])
		{
			pOut->ClearDrawArea();
			FigList[i]->Resize(S);
		}
	}
}
//Make SelectedFig unselect the Figure its pointer to NULL
void ApplicationManager::unselect()
{
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
	SelectedFig = NULL;
}

//==================================================================================//
//						Setter and Getters for APP Manager			     			//
//==================================================================================//

//check if the point chosen lies on a figure ->if yes returns ptr to fig / ->if no returns null
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->CheckSelected(x, y))
		{
			return FigList[i];
		}
	}
	 return NULL;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
} 
//get the  selectedfig from app manager
CFigure* ApplicationManager::GetSelected() const
{
	return SelectedFig;
} 
//get the (copied or cut) figure from clipboard app manager
CFigure* ApplicationManager::GetClipboard() const
{
	return Clipboard;
}
//get the figures count in the fig list
int ApplicationManager::getfigcountappmanager() const
{
	return FigCount;
}
//Set the selected fig (to copy or cut) in the clipboard
void ApplicationManager::SetClipboard(CFigure*D)
{
	Clipboard=D;
}
//Make SelectedFig select the Figure its pointer to the selected
void ApplicationManager::setselect(CFigure* C) //make SelectedFig Point to Selectedfigure
{
	if (SelectedFig != NULL)
	{
		SelectedFig->SetSelected(false);
	}
	SelectedFig = C;
	SelectedFig->SetSelected(true);
	if(C==NULL)
	{
		SelectedFig=NULL;
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if(FigList[i]!=NULL)
		{
			FigList[i]->Draw(pOut);
		}
		//Call Draw function (virtual member fn)
}
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
//perform cleanups before exit
void ApplicationManager::Exitfunction()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pOut; delete pIn;
	pIn = NULL; pOut = NULL;
	delete SelectedFig;
	delete Clipboard;
	SelectedFig = NULL; Clipboard = NULL;
}

////////////////////////////////////////////////////////////////////////////////////

//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}
