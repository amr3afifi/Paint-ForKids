#include "CFigure.h"

CFigure::CFigure()
{
	GfxInfo emptyGFX;
		emptyGFX.BorderWdth = 1;
		emptyGFX.DrawClr.ucBlue = 255; emptyGFX.DrawClr.ucGreen = 0; emptyGFX.DrawClr.ucRed = 0;
		emptyGFX.FillClr.ucBlue = 0; emptyGFX.FillClr.ucGreen = 0; emptyGFX.FillClr.ucRed = 0;
		emptyGFX.isFilled = 1;
FigGfxInfo = emptyGFX;
 
Selected = false;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void  CFigure::ChngBordWdth(int b)
{
	FigGfxInfo.BorderWdth = b;
}

bool CFigure::isEqual(CFigure*C)
{
	if(figtype()==C->figtype())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::SetID(int id)
{
	ID = id;
}

color CFigure::ReturnDrawClr(){
	return FigGfxInfo.DrawClr;
}

color CFigure::ReturnFillClr(){
	
	return FigGfxInfo.FillClr;
}

