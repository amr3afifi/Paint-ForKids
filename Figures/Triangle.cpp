
#include "Triangle.h"
#include <fstream>
#include <ostream>

Triangle::Triangle()
{
	Point emptyP;
	emptyP.x = 0; emptyP.y = 0;
	p1 = emptyP;
	p2 = emptyP;
	p3 = emptyP;

}

Triangle::Triangle(Point a,Point b,Point c,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo){

	
	p1 = a;
	p2 = b;
	p3 = c;}

void Triangle::Draw(Output* pOut) const
{ //Call Output::DrawTri to draw a triangle on the screen
	pOut->DrawTRI(p1,p2,p3,FigGfxInfo,Selected);
}

void Triangle::Rotate()
{
	double a1 = p1.x;
	double a2 = p2.x;
	double a3 = p3.x;
	double b1 = p1.y;
	double b2 = p2.y;
	double b3 = p3.y;
	p1.x = 2 * a3 - a1;
	p1.y = 2 * b3 - b1;
	p2.x = 2 * a3 - a2;
	p2.y = 2 * b3 - b2;

}

void Triangle::Resize(string S)
{
	if (S == "q")
	{
		float c = 0.25;
		double a1 = p1.x;
		double a2 = p2.x;
		double a3 = p3.x;
		double b1 = p1.y;
		double b2 = p2.y;
		double b3 = p3.y;
		double m21 = (b2 - b1) / (a2 - a1);
		double m32 = (b3 - b2) / (a3 - a2);
		double m31 = (b3 - b1) / (a3 - a1);
		double l = c*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double r = l / ((m21*m21) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m21*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;
		p3.x = (m32*p2.x - p2.y - m31*p1.x + p1.y) / (m32 - m31);
		p3.y = m32*(p3.x - p2.x) + p2.y;

	}
	else if (S == "h")
	{
		float c = 0.5;
		double a1 = p1.x;
		double a2 = p2.x;
		double a3 = p3.x;
		double b1 = p1.y;
		double b2 = p2.y;
		double b3 = p3.y;
		double m21 = (b2 - b1) / (a2 - a1);
		double m32 = (b3 - b2) / (a3 - a2);
		double m31 = (b3 - b1) / (a3 - a1);
		double l = c*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double r = l / ((m21*m21) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m21*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;
		p3.x = (m32*p2.x - p2.y - m31*p1.x + p1.y) / (m32 - m31);
		p3.y = m32*(p3.x - p2.x) + p2.y;

	}
	else if (S == "d")
	{
		float c = 2;
		double a1 = p1.x;
		double a2 = p2.x;
		double a3 = p3.x;
		double b1 = p1.y;
		double b2 = p2.y;
		double b3 = p3.y;
		double m21 = (b2 - b1) / (a2 - a1);
		double m32 = (b3 - b2) / (a3 - a2);
		double m31 = (b3 - b1) / (a3 - a1);
		double l = c*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double r = l / ((m21*m21) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m21*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;
		p3.x = (m32*p2.x - p2.y - m31*p1.x + p1.y) / (m32 - m31);
		p3.y = m32*(p3.x - p2.x) + p2.y;

	}
	else if (S == "qu")
	{
		float c = 4;
		double a1 = p1.x;
		double a2 = p2.x;
		double a3 = p3.x;
		double b1 = p1.y;
		double b2 = p2.y;
		double b3 = p3.y;
		double m21 = (b2 - b1) / (a2 - a1);
		double m32 = (b3 - b2) / (a3 - a2);
		double m31 = (b3 - b1) / (a3 - a1);
		double l = c*((pow((b2 - b1), 2)) + (pow((a2 - a1), 2)));
		double r = l / ((m21*m21) + 1);
		p2.x = 0.5*((sqrt(r)) + a1 + a2);
		p1.x = a2 + a1 - p2.x;
		p2.y = 0.5*(m21*(p2.x - p1.x) + b1 + b2);
		p1.y = b1 + b2 - p2.y;
		p3.x = (m32*p2.x - p2.y - m31*p1.x + p1.y) / (m32 - m31);
		p3.y = m32*(p3.x - p2.x) + p2.y;
	}



}

string Triangle::figtype()
{
	return "t";
}

CFigure* Triangle::copy()
{
	CFigure* Temp = new Triangle(p1, p2, p3, FigGfxInfo);
	return Temp;
}

CFigure* Triangle::paste(int x, int y)
{
	int dist1x, dist1y,dist2x, dist2y;
	dist1x = (p2.x - p1.x); dist1y = (p2.y - p1.y);
	dist2x = (p3.x - p1.x); dist2y = (p3.y - p1.y);

	Point np1; Point np2; Point np3;
	np1.x = x; np1.y = y;
	np2.x = x+dist1x; np2.y = y + dist1y;
	np3.x = x+dist2x; np3.y = y + dist2y;

	GfxInfo GfxInfo = FigGfxInfo;
	CFigure *R = new Triangle(np1, np2, np3, GfxInfo);
	R->SetID(rand());
	return R;
}

void Triangle::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(p1.x) + "," + to_string(p1.y) + ")";
	string y = "(" + to_string(p2.x) + "," + to_string(p2.y) + ")";
	string z = "(" + to_string(p3.x) + "," + to_string(p3.y) + ")";
	string id = to_string(ID);
	pOut->PrintMessage("Triangle: ID= " +id+", Vertex1 = " + x + " , Vertex2 = " + y + " , Vertex3 = " + z);
}
void Triangle::Save(ofstream &save){
	save << "Triangle" << endl;
	save <<ID << endl;
	save << p1.x << " " << p1.y << endl;
	save << p2.x << " " <<p2.y << endl;
	save << p3.x << " " <<p3.y << endl;
	save << FigGfxInfo.BorderWdth << endl;

	if(FigGfxInfo.DrawClr==ORANGE)
		save <<"ORANGE"<<endl;

	if(FigGfxInfo.DrawClr==BLACK)
		save <<"BLACK"<<endl;
	if(FigGfxInfo.DrawClr==BLUE)
	save <<"BLUE"<<endl;
	if(FigGfxInfo.DrawClr==RED)
		save <<"RED"<<endl;
	if(FigGfxInfo.DrawClr==GREEN)
		save<<"GREEN"<<endl;
	save  <<FigGfxInfo.isFilled<<endl; //save el filclr 

	if(FigGfxInfo.FillClr==ORANGE)
		save <<"ORANGE"<<endl;
	if(FigGfxInfo.FillClr==BLACK)
		save <<"BLACK"<<endl;
	if(FigGfxInfo.FillClr==BLUE)
	save <<"BLUE"<<endl;
	if(FigGfxInfo.FillClr==RED)
		save <<"RED"<<endl;
	if(FigGfxInfo.FillClr==GREEN)
		save<<"GREEN"<<endl;
	save << endl;
}
void Triangle::Load(ifstream &load)
{
	load >> ID;
	load >> p1.x >> p1.y;
	load >> p2.x >> p2.y;
	load >> p3.x >> p3.y;
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
		FigGfxInfo.FillClr = WHITE;}}
	
	

bool Triangle::CheckSelected(int a, int b)
{
	Point check;
	check.x = a;
	check.y = b;

	float areaTotal = abs(p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / (2);

	float area1 = abs(check.x*(p2.y - p3.y) + p2.x*(p3.y - check.y) + p3.x*(check.y - p2.y)) / (2);
	float area2 = abs(p1.x*(check.y - p3.y) + check.x*(p3.y - p1.y) + p3.x*(p1.y - check.y)) / (2);
	float area3 = abs(p1.x*(p2.y - check.y) + p2.x*(check.y - p1.y) + check.x*(p1.y - p2.y)) / (2);
	if ((area1 + area2 + area3 <= areaTotal)){
		return true;
	}
	return false;
}

