#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");
	
	CreateDesignToolBar();	//Create the desgin toolbar
	CreateSimulationToolBar();
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(DARKPURPLE, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight+5, UI.width, UI.height - UI.StatusBarHeight-UI.SimBarHeight-8);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR22.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\Menu_XOR.jpg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\Menu_XNOR.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_BUFF.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED2.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_Wire.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(TEAL, 3);
	pWind->DrawLine(0, UI.ToolBarHeight+3, UI.width, UI.ToolBarHeight+3);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\Simulation.jpg";
	MenuItemImages[ITM_ADD_Label] = "images\\Menu\\EditLabel.jpg";
	MenuItemImages[ITM_EDIT_Label] = "images\\Menu\\AddLabel.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\TruthTable.jpg";
	MenuItemImages[ITM_CHANGE_SWITCH] = "images\\Menu\\ChangeSwitch.jpg";
	MenuItemImages[ITM_DEL] = "images\\Menu\\Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\Move.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Load.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Redo.jpg";
	MenuItemImages[ITM_DSN_MODE] = "images\\Menu\\Design.jpg";
	MenuItemImages[ITM_SIM_MODE] = "images\\Menu\\Simulation.jpg";
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], (i * UI.SimItemWidth),UI.height-UI.SimBarHeight-UI.StatusBarHeight-2, UI.SimItemWidth, UI.SimBarHeight);

	//Draw a line below the simulation bar
	pWind->SetPen(TEAL, 3);
	pWind->DrawLine(0, UI.height - UI.SimBarHeight - UI.StatusBarHeight-6, UI.width, UI.height - UI.SimBarHeight - UI.StatusBarHeight-6);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components


void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.AND2_Height);
}


void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}


void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOT_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFFER.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}

///////////////////////////////////////////////////////////////////
// LEDs and switches

void Output::DrawLEDOFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\LEDnSwitches\\LED_select.jpg";
	else
		GateImage = "Images\\LEDnSwitches\\LED.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawLEDON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\LEDnSwitches\\LED_Hi_select.jpg";
	else
		GateImage = "Images\\LEDnSwitches\\LED_Hi.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawSWITCHOFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\LEDnSwitches\\switch_on_select.jpg";
	else
		GateImage = "Images\\LEDnSwitches\\switch_on.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawSWITCHON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\LEDnSwitches\\switch_off_select.jpg";
	else
		GateImage = "Images\\LEDnSwitches\\switch_off.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	int mid_point;
	if (selected) {
		pWind->SetPen(RED, 2);
		if (r_GfxInfo.y1 != r_GfxInfo.y2) {

			if (r_GfxInfo.x1 < r_GfxInfo.x2) {
				mid_point = r_GfxInfo.x1 + (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, mid_point, r_GfxInfo.y1);
				pWind->DrawLine(mid_point, r_GfxInfo.y1, mid_point, r_GfxInfo.y2);
				pWind->DrawLine(mid_point, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
			}
			else
			{
				mid_point = r_GfxInfo.x2 + (r_GfxInfo.x1 - r_GfxInfo.x2) / 2;
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, mid_point, r_GfxInfo.y1);
				pWind->DrawLine(mid_point, r_GfxInfo.y1, mid_point, r_GfxInfo.y2);
				pWind->DrawLine(mid_point, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
			}

		}
		else {
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		}
	}
	else
	{
		pWind->SetPen(BLACK, 2);
		if (r_GfxInfo.y1 != r_GfxInfo.y2) {

			if (r_GfxInfo.x1 < r_GfxInfo.x2) {
				mid_point = r_GfxInfo.x1 + (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, mid_point, r_GfxInfo.y1);
				pWind->DrawLine(mid_point, r_GfxInfo.y1, mid_point, r_GfxInfo.y2);
				pWind->DrawLine(mid_point, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
			}
			else
			{
				mid_point = r_GfxInfo.x2 + (r_GfxInfo.x1 - r_GfxInfo.x2) / 2;
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, mid_point, r_GfxInfo.y1);
				pWind->DrawLine(mid_point, r_GfxInfo.y1, mid_point, r_GfxInfo.y2);
				pWind->DrawLine(mid_point, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
			}

		}
		else {
			pWind->SetPen(BLACK, 2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		}
	}

}



Output::~Output()
{
	delete pWind;
}
