#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	ROTATE,        
	SAVE,			//Save the whole graph to a file
	LOAD,   //Load a graph from a file
	COPY,   
	PASTE,
	SELECT,
	RESIZE,
	CUT,
	rED,
	bLACK,
	gREEN,
	wHITE,
	bLUE,
	oRANGE,
	BorderWidth,
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY	,		//Switch interface to Play mode
	PICK_HIDE ,      //PICK AND HIDE GAME
	PICK_TYPE ,        //PICK AND HIDE TYPE GAME
	PICK_BOTH//PICK AND HIDE BOTH GAME
	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
	
};

#endif