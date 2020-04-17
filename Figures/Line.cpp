#include"..\ApplicationManager.h"
#include "Line.h"
#include <fstream>
#include <ostream>

CLine::CLine()
{
	Point emptyP;
	emptyP.x = 0; emptyP.y = 0;
	p1=emptyP;
	p2=emptyP;


}

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p1=P1;
	p2=P2;
}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(p1, p2, FigGfxInfo, Selected);
}


void CLine::Rotate()
{
	double a1 = p1.x
		, a2 = p2.x,
		b1 = p1.y
		, b2 = p2.y;
	double m = -((a2 - a1) / (b2 - b1));
	double l = (pow((b2 - b1), 2)) + (pow((a2 - a1), 2));
	double r = (l / ((m*m) + 1));
	p2.x = 0.5*((sqrt(r)) + a1 + a2);
	p1.x = a1 + a2 - p2.x;
	p1.y = 0.5*(b1 + b2 - m*(p2.x - p1.x));
	p2.y = b1 + b2 - p1.y;

}

void CLine::Resize(string S)
{

	if (S == "q")
	{
		double a1 = p1.x;
		double b1 = p1.y;
		double a2 = p2.x;
		double b2 = p2.y;
		double l = (pow(0.25, 2))*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double m = (b2 - b1) / (a2 - a1);
		double r = l / ((m*m) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;

	}
	else if (S == "h")
	{
		double a1 = p1.x;
		double b1 = p1.y;
		double a2 = p2.x;
		double b2 = p2.y;
		double l = (pow(0.5, 2))*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double m = (b2 - b1) / (a2 - a1);
		double r = l / ((m*m) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;

	}
	else if (S == "d")
	{
		double a1 = p1.x;
		double b1 = p1.y;
		double a2 = p2.x;
		double b2 = p2.y;
		double l = (pow(2, 2))*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double m = (b2 - b1) / (a2 - a1);
		double r = l / ((m*m) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;

	}
	else if (S == "qu")
	{
		double a1 = p1.x;
		double b1 = p1.y;
		double a2 = p2.x;
		double b2 = p2.y;
		double l = (pow(4, 2))*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double m = (b2 - b1) / (a2 - a1);
		double r = l / ((m*m) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;

	}
}

string CLine::figtype()
{
	return "l";
}

bool CLine::CheckSelected(int a, int b)
{
		double d1 = sqrt((a - p1.x)*(a - p1.x) + (b - p1.y)*(b - p1.y));
		double d2 = sqrt((a - p2.x)*(a - p2.x) + (b - p2.y)*(b - p2.y));
		double dt = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
		return ((d1 + d2) == dt || (d1 + d2 - dt) <= 0.5);
}

void CLine::PrintInfo(Output* pOut)
{
	string po1 = "(" + to_string(p1.x) + "," + to_string(p1.y) + ")";
	string po2 = "(" + to_string(p2.x) + "," + to_string(p2.y) + ")";
	int dist =abs(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
	string disto = to_string(dist);
	string id = to_string(ID);
	pOut->PrintMessage("Line: ID= " +id+", EndPoint1= " + po1 + " , EndPoint2= " + po2 + " , Distance= " + disto);
}

CFigure* CLine::copy()
{
	CFigure* Temp = new CLine(p1, p2, FigGfxInfo);
	return Temp;
}

CFigure* CLine::paste(int x, int y)
{
	const int length = abs(p1.x - p2.x)/2;
	const int width = abs(p1.y - p2.y)/2;
	Point np1; Point np2;
	np1.x = x-length; np1.y = y-width;
	np2.x = x + length; np2.y = y + width;
	GfxInfo GfxInfo = FigGfxInfo;
	CFigure *R = new CLine(np1, np2, GfxInfo);
	ApplicationManager*p;
	R->SetID(rand());
	return R;
}

void CLine::Save(ofstream &save)
{
	save << "Line" << endl;
	save << ID << endl;
	save << p1.x << " " << p1.y << endl;
	save << p2.x <<" "<< p2.y<<endl;
	save << FigGfxInfo.BorderWdth << endl;
	if(FigGfxInfo.DrawClr==ORANGE)
		save <<"ORANGE"<<endl;
	if(FigGfxInfo.DrawClr==BLACK)
		save << "BLACK" << endl;
	if(FigGfxInfo.DrawClr==BLUE)
	save <<"BLUE"<<endl;
	if(FigGfxInfo.DrawClr==RED)
		save <<"RED"<<endl;
	if(FigGfxInfo.DrawClr==GREEN)
		save<<"GREEN"<<endl;
	save << endl;
}

void CLine::Load(ifstream &load)
{
		
		int id;
		load >> id;
		load >> p1.x >> p1.y;
		load >> p2.x >> p2.y;
		load >> FigGfxInfo.BorderWdth;
		string drwclr;
	
	load>>drwclr;
	
	if(drwclr=="ORANGE")
		FigGfxInfo.DrawClr=ORANGE;
	if(drwclr=="BLACK")
		FigGfxInfo.DrawClr=BLACK;
	if(drwclr=="BLUE")
		FigGfxInfo.DrawClr=BLUE;
	if(drwclr=="RED")
			FigGfxInfo.DrawClr=RED;
	if(drwclr=="GREEN")
		FigGfxInfo.DrawClr=GREEN;
	FigGfxInfo.isFilled = false;
}
		
CLine::~CLine()
{
}
