 #ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool CheckSelected(int x,int y);
	void Rotate();
	void Resize(string S);
	virtual CFigure* copy();
    CFigure* paste(int x, int y);
	void PrintInfo(Output* pOut);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	string figtype();
};

#endif