#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures/CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		            //Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig;           //Pointer to the selected figure
	CFigure* Clipboard;             //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	ActionType GetUserAction() const;       //Reads the input command from the user and returns the corresponding action type
	void ExecuteAction(ActionType) ;        //Creates an action and executes it
	
	// -- Setters and Getters Functions from App manager
	void setselect(CFigure*);               //Make SelectedFig select the Figure its pointer to the selected
	void SetClipboard(CFigure*C);           //Set the selected fig (to copy or cut) in the clipboard
	CFigure*GetSelected() const;            //get the  selectedfig from app manager
	CFigure*GetClipboard() const;           //get the (copied or cut) figure from clipboard app manager
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int getfigcountappmanager() const;      //get the figures count in the fig list

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void copyfigure();                      //Copy a figure from the FigList
	void RemoveFigure();	                //Remove the selected figure 
	void SaveAll(ofstream &save);           //saves  ALL figures
	void RemoveAll();                       //removes all figures
	void unselect();                        //Make SelectedFig unselect the Figure its pointer to NULL
	void Rotate();                          //Rotate selected figure from the list of Figures
	void resize(string);                    //Resize selected figure from the list of Figures

	// -- Play Mode Functions
	int CountFigures(color A);              //return count the figures with the required color
	int CountFigures(CFigure*C);            //return count the figures with the required type
	int CountFigures(CFigure*C,color A);    //return count the figures with the required type and color
	bool CheckColor(color A);               // check color of selected fig in the game matches with required ->if yes return true ->if no return false
	bool CheckType(CFigure*C);              // check type of selected fig in the game matches with required ->if yes return true ->if no return false
	bool CheckBoth(CFigure*C,color A);      // check type and color of selected fig in the game matches with required ->if yes return true ->if no return false
	
	// -- Interface Management Functions
	Input *GetInput() const;                //Return pointer to the input
	Output *GetOutput() const;              //Return pointer to the output
	void UpdateInterface() const;	        //Redraws all the drawing window
	void Exitfunction();                    //perform clean ups before exit
};

#endif