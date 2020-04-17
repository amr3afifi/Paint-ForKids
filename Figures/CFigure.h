#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	                  //select/unselect the figure
	bool IsSelected() const;	                  //check whether fig is selected
	virtual void Rotate() = 0;                    //Rotate each figure
	virtual void Resize(string S) = 0;            //Resize by given ratio
	virtual bool CheckSelected(int x, int y)=0;   //check if point lies into the figure
	virtual void Draw(Output* pOut) const  = 0 ;  //Draw the figure
	virtual string figtype() = 0;                 //return figure type
	virtual CFigure* paste(int x, int y) = 0;     //paste each figure
	virtual CFigure* copy() = 0;                  //copy each figure
	void SetID(int id);                           //set if for each figure
	bool isEqual(CFigure*C);                      //check if figure type matches another given figure
	color ReturnDrawClr();                        //retrun draw color of figure
	color ReturnFillClr();                        //retrun fill color of figure
	
	void ChngDrawClr(color Dclr);	              //changes the figure's drawing color
	void ChngFillClr(color Fclr);	              //changes the figure's filling color
	void ChngBordWdth(int b);                     //changes border width of figure

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	  //Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	  //Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	  //print all figure info on the status bar
};

#endif