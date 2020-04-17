
#include "CRectangle.h"
#include <fstream>
#include <iostream>

CRectangle ::CRectangle()
{
Point emptyP;
emptyP.x = 0; emptyP.y = 0;
Corner1 =emptyP;
Corner2 =emptyP;
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

}

void CRectangle::Rotate()
{
	double t11, t12, t21, t22;
	t11 = Corner1.x;
	t12 = Corner1.y;
	t21 = Corner2.x;
	t22 = Corner2.y;
	Point m;
	m.x = (t11 + t21) / 2;
	m.y = (t12 + t22) / 2;
	Corner2.x = (2 * m.x + t12 - t22) / 2;
	Corner1.x = 2 * m.x - Corner2.x;
	Corner2.y = (2 * m.y + t11 - t21) / 2;
	Corner1.y = abs(2 * m.y - Corner2.y);
}

void CRectangle::Resize(string C)
{
	if (C == "q")
	{
		double a1 = Corner1.x
			, b1 = Corner1.y, a2 = Corner2.x, b2 = Corner2.y;
		Corner2.x = (a1 + a2 + sqrt(0.25)*abs(a1 - a2)) / 2;
		Corner1.x = a1 + a2 - Corner2.x;
		Corner2.y = (b1 + b2 + sqrt(0.25)*abs(b1 - b2)) / 2;
		Corner1.y = b1 + b2 - Corner2.y;
	}
	else if (C == "h")
	{
		double a1 = Corner1.x
			, b1 = Corner1.y, a2 = Corner2.x, b2 = Corner2.y;
		Corner2.x = (a1 + a2 + sqrt(0.5)*abs(a1 - a2)) / 2;
		Corner1.x = a1 + a2 - Corner2.x;
		Corner2.y = (b1 + b2 + sqrt(0.5)*abs(b1 - b2)) / 2;
		Corner1.y = b1 + b2 - Corner2.y;
	}
	else if (C == "d")
	{
		double a1 = Corner1.x
			, b1 = Corner1.y, a2 = Corner2.x, b2 = Corner2.y;
		Corner2.x = (a1 + a2 + sqrt(2)*abs(a1 - a2)) / 2;
		Corner1.x = a1 + a2 - Corner2.x;
		Corner2.y = (b1 + b2 + sqrt(2)*abs(b1 - b2)) / 2;
		Corner1.y = b1 + b2 - Corner2.y;
	}
	else if (C == "qu")
	{
		double a1 = Corner1.x
			, b1 = Corner1.y, a2 = Corner2.x, b2 = Corner2.y;
		Corner2.x = (a1 + a2 + sqrt(4)*abs(a1 - a2)) / 2;
		Corner1.x = a1 + a2 - Corner2.x;
		Corner2.y = (b1 + b2 + sqrt(4)*abs(b1 - b2)) / 2;
		Corner1.y = b1 + b2 - Corner2.y;
	}

}

bool CRectangle::CheckSelected(int x, int y)
{
	if ((x >= Corner1.x && x <= Corner2.x) && (y >= Corner1.y && y <= Corner2.y) || (x <= Corner1.x && x >= Corner2.x) && (y <= Corner1.y && y >= Corner2.y)|| (x >= Corner1.x && x <= Corner2.x) && (y <= Corner1.y && y >= Corner2.y) || (x <= Corner1.x && x >= Corner2.x) && (y >= Corner1.y && y <= Corner2.y) )
	{
		return true;
	}
	return false;
}

string CRectangle::figtype()
{
	return "r";
}

CFigure* CRectangle::copy()
{
	CFigure* Temp = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return Temp;
}


CFigure* CRectangle::paste(int x, int y)
{
	const int length = abs(Corner1.x-Corner2.x);
	const int width = abs(Corner1.y - Corner2.y);
	Point p1; Point p2;
	p1.x = x; p1.y = y;
	p2.x = p1.x + length;
	p2.y = p1.y + width;
	GfxInfo RecGfxInfo = FigGfxInfo;
	CFigure *R = new CRectangle(p1, p2, RecGfxInfo);
	R->SetID(rand());
	return R;
}

void CRectangle::PrintInfo(Output* pOut)
{
	string l = to_string(abs(Corner1.x - Corner2.x));
	string w = to_string(abs(Corner1.y - Corner2.y));
	string id = to_string(ID);
	string c1 = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string c2 = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage("Rectangle: ID= " + id + ",Corner1= " +c1+ ",Corner2= " +c2+ ", Length = " + l + ", Width = " + w);

}
void CRectangle::Save(ofstream &save){
	save << "Rectangle" << endl;
	save << ID << endl;
	save << Corner1.x <<" " << Corner1.y<<endl;
	save << Corner2.x <<" "<< Corner2.y<<endl;
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

void CRectangle::Load(ifstream &load){
	
	
	load >> ID;
	load >> Corner1.x >> Corner1.y;
	load >> Corner2.x >> Corner2.y;
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
	if(filclr=="GREEN")
	{
		FigGfxInfo.FillClr=GREEN;
	}
	}
	else
	{
		FigGfxInfo.FillClr = WHITE;
	}
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}