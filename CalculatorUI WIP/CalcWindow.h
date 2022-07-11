#pragma once
#include "wx/wx.h"
/*
I plan on emulating the Windows 10 Calculator, there may be some design obstacles that i'll have to overcome, but its an interesting design challenge.
I'm going to be using ScreenRuler Software to get accurate measurements of the Default microwindow size of the Windows 10 Calculator, and build around that.
I do plan on using Grids for the 0-9 Keys, but since it is an odd number its going to be finnicky, so i'll just do a 3x3 matrix of 1-9 with the 0 as an independent button
outside of that.
*/

class CalcWindow : public wxFrame
{
public:
	//Constructor and Destructor for the window Frame
	CalcWindow();
	~CalcWindow();

	//Keypad Dimensions 80x45px
	//This goes for all the keypad buttons, the exception to this are the HEX DEC and BIN displays
	//type Display Dimensions are 70x55px
	int KeypadWidth = 80;
	int keypadHeight = 45;

	int typeDisplayWidth = 70;
	int typeDisplayHeight = 55;

	wxButton** keypadDigits;

	//The Grid Area for the Keys themselves.
	int* keypadArea = nullptr;


private: 
	//Graphics Display
	wxTextCtrl* CalculatorDisplay;
	wxTextCtrl* CalcBinDisplay;
	wxTextCtrl* CalcHexDisplay;
	wxTextCtrl* CalcDecDisplay;
	//Numpad Function Keys (+,-.*,/,C,
	wxButton* calcPlus;
	wxButton* calcMinus;
	wxButton* calcMult;
	wxButton* calcDiv;
	wxButton* calcClear;
	wxButton* calcMod;
	// im dumb and this shouldnt exist wxButton* calcZero;
	wxButton* calcEqual;
	
	wxDECLARE_EVENT_TABLE();
	void OnButtonClicked(wxCommandEvent& evt);

};

