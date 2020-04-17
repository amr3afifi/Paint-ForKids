#include "Circle.h"
#include <fstream>
#include <ostream>

CCircle::CCircle()
{
	Point emptyP;
emptyP.x = 0; emptyP.y = 0;
Center = emptyP;
Otherpoint =emptyP;

}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Otherpoint = P2;
}

CFigure* CCircle::copy()
{
	//creates an exact copy of the current object
	CFigure* Temp = new CCircle(Center, Otherpoint, FigGfxInfo);
	return Temp;
}


CFigure* CCircle::paste(int x, int y)
{
	const int radius = sqrt(pow(Center.x - Otherpoint.x, 2) + pow(Center.y - Otherpoint.y, 2));
	Point p1; Point p2;
	p1.x = x; p1.y = y;
	p2.x = p1.x - radius;
	p2.y = p1.y;
	GfxInfo CircGfxInfo = FigGfxInfo;
	CFigure *R = new CCircle(p1, p2, CircGfxInfo);
	R->SetID(rand());
	return R;
}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen
	pOut->DrawCircle(Center, Otherpoint, FigGfxInfo, Selected);
}

string CCircle::figtype()
{
	return "c" ;
}

void CCircle::Rotate()
{

}

void CCircle::Resize(string S)
{


	if (S == "q")
	{
		double cx = ((Otherpoint.x + Center.x) / 2);
		double cy = ((Otherpoint.y + Center.y) / 2);
		Otherpoint.x = (cx + Center.x) / 2;
		Otherpoint.y = (cy + Center.y) / 2;
	}
	else if (S == "h")
	{
		Otherpoint.x = ((Otherpoint.x + Center.x) / 2);
		Otherpoint.y = ((Otherpoint.y + Center.y) / 2);
	}
	else if (S == "d")
	{
		Otherpoint.x = 2 * Otherpoint.x - Center.x;
		Otherpoint.y = 2 * Otherpoint.y - Center.y;
	}
	else if (S == "qu")
	{
		double dx = 2 * Otherpoint.x - Center.x;
		double dy = 2 * Otherpoint.y - Center.y;
		Otherpoint.x = 2 * dx - Center.x;
		Otherpoint.y = 2 * dy - Center.y;
	}
}

bool CCircle::CheckSelected(int x, int y)
{
	int radius = sqrt(pow(Center.x - Otherpoint.x, 2) + pow(Center.y - Otherpoint.y, 2));
	if (y >= (Center.y - radius) && y <= (Center.y + radius))
	{
		if (x >= (Center.x - radius) && x <= (Center.x + radius))
		{
			return true;
		}
		return false;
	}
	return false;
}

void CCircle::PrintInfo(Output* pOut) 
{
	string radius = to_string(abs(Otherpoint.x-Center.x));
	string id = to_string(ID);
	string c = "(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	pOut->PrintMessage("Circle: ID= " +id+" Radius = " + radius + ", Center = " + c );
	
}

void CCircle::Save(ofstream &save){
	save << "Circle" << endl;
	save << ID << endl;
	save << Center.x <<" "<< Center.y<<endl;
	save << Otherpoint.x <<" "<< Otherpoint.y<<endl;
	save << FigGfxInfo.BorderWdth << endl;
	
	if(FigGfxInfo.DrawClr==ORANGE){
		save <<"ORANGE"<<endl;}

	if(FigGfxInfo.DrawClr==BLACK){
		save <<"BLACK"<<endl;
	}
	
	if(FigGfxInfo.DrawClr==BLUE){
	save <<"BLUE"<<endl;
	}
	
	if(FigGfxInfo.DrawClr==RED){
		save <<"RED"<<endl;}
	
	if(FigGfxInfo.DrawClr==GREEN){
		save<<"GREEN"<<endl;}

	
	
	save  <<FigGfxInfo.isFilled<<endl; //save el filclr 

	
	if(FigGfxInfo.FillClr==ORANGE){
		save <<"ORANGE"<<endl;}

	if(FigGfxInfo.FillClr==BLACK){
		save <<"BLACK"<<endl;
	}
	
	if(FigGfxInfo.FillClr==BLUE){
	save <<"BLUE"<<endl;
	}
	
	if(FigGfxInfo.FillClr==RED){
		save <<"RED"<<endl;}
	
	if(FigGfxInfo.FillClr==GREEN){
		save<<"GREEN"<<endl;}
	save << endl;
}


void CCircle::Load(ifstream &load){
	
	
	load >> ID;
	load >> Center.x >> Center.y;
	load >> Otherpoint.x >> Otherpoint.y;
	GfxInfo Info;
	int fillcheck[3];
	load >> FigGfxInfo.BorderWdth;
	string drwclr;
	
	load>>drwclr;
	
	if(drwclr=="ORANGE"){
		FigGfxInfo.DrawClr=ORANGE;}
	if(drwclr=="BLACK"){
		FigGfxInfo.DrawClr=BLACK;}
	if(drwclr=="BLUE"){
		FigGfxInfo.DrawClr=BLUE;
	}
	if(drwclr=="RED"){
			FigGfxInfo.DrawClr=RED;}
	if(drwclr=="GREEN"){
		FigGfxInfo.DrawClr=GREEN;}
	if (drwclr == "WHITE"){
		FigGfxInfo.DrawClr = WHITE;
	}
	load >> FigGfxInfo.isFilled;
	
	if(FigGfxInfo.isFilled){
	string filclr;
	load>>filclr;

	if(filclr=="ORANGE"){
		FigGfxInfo.FillClr=ORANGE;}
	if(filclr=="BLACK"){
		FigGfxInfo.FillClr=BLACK;}
	if(filclr=="BLUE"){
		FigGfxInfo.FillClr=BLUE;
	}
	if(filclr=="RED"){
			FigGfxInfo.FillClr=RED;}
	if(filclr=="GREEN"){
		FigGfxInfo.FillClr=GREEN;}
	}
	else{
		FigGfxInfo.FillClr = WHITE;}
}

CCircle::~CCircle()
{
}
