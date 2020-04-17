#pragma once
#include "CFigure.h"

class Triangle :public CFigure
{
	Point p1, p2, p3;
public:
	Triangle();
	Triangle(Point a,Point b,Point c,GfxInfo FigureGfxInfo);
     virtual void Draw(Output* pOut) const;
	 bool CheckSelected(int a,int b);
	 void Rotate();
	 virtual CFigure* copy();
	 void Resize(string C);
	 CFigure* paste(int x, int y);
	 void PrintInfo(Output* pOut);
	 virtual void Save(ofstream &OutFile);
	 virtual void Load(ifstream &Infile);
	 string figtype();
};

