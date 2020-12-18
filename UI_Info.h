#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	const int	width = 1400, height = 800,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 70,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 90,		//Width of each item in toolbar menu
		SimBarHeight = 70,
		SimItemWidth = 90;
	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	const int	AND2_Width = 80,		//AND2 Gate Image default width
				AND2_Height = 55,		//AND2 Gate Image default height

				OR2_Width = 90,
				OR2_Height = 55,
				
				NOR2_Width = 85,
				NOR2_Height = 55,

				NOT_Width = 85,
				NOT_Height = 70;
	
}UI;	//create a single global object UI

#endif
