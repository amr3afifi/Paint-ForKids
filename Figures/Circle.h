#pragma once
#include "CFigure.h"

class CCircle :
	public CFigure
{ private:
	Point Center;
	Point Otherpoint;
public:
	CCircle();
	CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool CheckSelected(int x,int y);
	void Rotate();
	void Resize(string S);
	virtual CFigure* copy();
	CFigure* paste(int x, int y);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	void PrintInfo(Output* pOut);
	string figtype();
	~CCircle();
};

