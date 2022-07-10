#include "CalcWindow.h"
#include "string"
/*
I plan on emulating the Windows 10 Calculator, there may be some design obstacles that i'll have to overcome, but its an interesting design challenge.
I'm going to be using ScreenRuler Software to get accurate measurements of the Default microwindow size of the Windows 10 Calculator, and build around that.
I do plan on using Grids for the 0-9 Keys, but since it is an odd number its going to be finnicky, so i'll just do a 3x3 matrix of 1-9 with the 0 as an independent button
outside of that.

huh yeah grids are funky.
grids are so weird.
why are grids annoying.

I really REALLY don't want to hardcode positions but good god does this make me want to hardcode positions



*/

CalcWindow::CalcWindow() : wxFrame(nullptr, wxID_ANY, "Calculator UI Draft", wxPoint(100, 100), wxSize(335, 535)) {
	//Calculator Display
	//ok  so turns out hardcoding size is a really bad choice
	//i've made things so much worse for myself by doing that, and i hatemyself for thinking "oh it'll be easy, just make everything just like windows!"
	//truly i am a hinderence to my own self.
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxFont font(48, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_MAX, wxFONTWEIGHT_BOLD, false);
	// though, i do like how there is a right align, so i can at least kinda keep the windows 10 dream alive.
	CalculatorDisplay = new wxTextCtrl(panel, wxID_ANY, "0",wxDefaultPosition,wxSize(335,75),wxTE_RIGHT);
	CalculatorDisplay->SetFont(font);
	CalcBinDisplay = new wxTextCtrl(panel, wxID_ANY, "Bin: 0", wxDefaultPosition, wxDefaultSize, wxTE_LEFT);
	CalcDecDisplay = new wxTextCtrl(panel, wxID_ANY, "Dec: 0", wxDefaultPosition, wxDefaultSize, wxTE_LEFT);
	CalcHexDisplay = new wxTextCtrl(panel, wxID_ANY, "Hex: 0", wxDefaultPosition, wxDefaultSize, wxTE_LEFT);

	keypadDigits = new wxButton * [10];
	//4x3 Matrix of numpad Keys, overloads are (Rows, Columns, vgap, hgap)
	// turns out the 0 key is really cringe to work with, so i'm making the matrix a 4x3, which is cringe i know but i have to do it.
	//*adendum, im doing something really stupid and im upping the grid size to 6x3
	wxGridSizer* keypadSizer = new wxGridSizer(7,3,0,0);
	
	// i dont even know if i use this like ever.
	//keypadArea = new int[KeypadWidth * keypadHeight];
	//i thought i was gonna need the keypad area to designate a sizer space, but i guess not :(


	//this sizer grid is being so cringe right now, it keeps going under the display and looks so bad. 
	//HAHA 
	for (int i = 0; i != 10; i++)
	{
		keypadDigits[i] = new wxButton(panel, i, std::to_string(i), wxDefaultPosition, wxSize(80, 45));
		keypadSizer->Add(keypadDigits[i], 1, wxEXPAND | wxALL);
	}
	//Function Buttons 
	//Numpad Function Keys (+,-.*,/,C,%,=)
	calcPlus = new wxButton(panel,30000,"+",wxDefaultPosition,wxSize(80,45)); keypadSizer->Add(calcPlus,1,wxEXPAND|wxALL);
	calcMinus = new wxButton(panel, 30001, "-", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcMinus, 1, wxEXPAND | wxALL);
	calcMult = new wxButton(panel, 30002, "*", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcMult, 1, wxEXPAND | wxALL);
	calcDiv = new wxButton(panel, 30003, "/", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcDiv, 1, wxEXPAND | wxALL);
	calcMod = new wxButton(panel, 30004, "%", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcMod, 1, wxEXPAND | wxALL);
	calcClear = new wxButton(panel, 30005, "C", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcClear, 1, wxEXPAND | wxALL);
	calcEqual = new wxButton(panel, 30006, "=", wxDefaultPosition, wxSize(80, 45)); keypadSizer->Add(calcEqual, 1, wxEXPAND | wxALL);

	
	wxBoxSizer* gridFoundation = new wxBoxSizer(wxVERTICAL);
	gridFoundation->Add(CalculatorDisplay, wxSizerFlags(0).Expand().Border(wxALL));
	gridFoundation->Add(CalcBinDisplay, wxSizerFlags(0).Expand().Border(wxALL));
	gridFoundation->Add(CalcDecDisplay, wxSizerFlags(0).Expand().Border(wxALL));
	gridFoundation->Add(CalcHexDisplay, wxSizerFlags(0).Expand().Border(wxALL));
	gridFoundation->Add(keypadSizer, wxSizerFlags(0).Expand().Border(wxLEFT | wxRIGHT | wxBOTTOM));
	panel->SetSizer(gridFoundation);
	
	/* This was adapted froma  post from New Pagodi on 2021/06/01 on Stackoverflow forum post here: 
	https://stackoverflow.com/questions/67787519/wxwidgets-gridsizer-puts-all-buttons-in-the-same-position
	*/
}

CalcWindow::~CalcWindow() {
	delete[] keypadDigits;
}