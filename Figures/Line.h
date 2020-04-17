#pragma once
#include "CFigure.h"
class CLine :
	public CFigure
{
	Point p1;
	Point p2;
public:
	CLine();
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool CheckSelected(int x,int y);
	CFigure* paste(int x, int y);
	void Rotate();
	virtual CFigure* copy();
	void Resize(string S);
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	string figtype();
	~CLine();
};

