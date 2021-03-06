#include "CalcWindow.h"
#include "ButtonFactory.h"
#include "string"
#include "CalculatorProcessor.h"
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

CalcProcessor* processor = CalcProcessor::GetInstance();

wxBEGIN_EVENT_TABLE(CalcWindow,wxFrame)
EVT_BUTTON(0, CalcWindow::OnButtonClicked)
EVT_BUTTON(1, CalcWindow::OnButtonClicked)
EVT_BUTTON(2, CalcWindow::OnButtonClicked)
EVT_BUTTON(3, CalcWindow::OnButtonClicked)
EVT_BUTTON(4, CalcWindow::OnButtonClicked)
EVT_BUTTON(5, CalcWindow::OnButtonClicked)
EVT_BUTTON(6, CalcWindow::OnButtonClicked)
EVT_BUTTON(7, CalcWindow::OnButtonClicked)
EVT_BUTTON(8, CalcWindow::OnButtonClicked)
EVT_BUTTON(9, CalcWindow::OnButtonClicked)
EVT_BUTTON(30000,CalcWindow::OnButtonClicked)
EVT_BUTTON(30001, CalcWindow::OnButtonClicked)
EVT_BUTTON(30002, CalcWindow::OnButtonClicked)
EVT_BUTTON(30003, CalcWindow::OnButtonClicked)
EVT_BUTTON(30004, CalcWindow::OnButtonClicked)
EVT_BUTTON(30005, CalcWindow::OnButtonClicked)
EVT_BUTTON(30006, CalcWindow::OnButtonClicked)
wxEND_EVENT_TABLE()


CalcWindow::CalcWindow() : wxFrame(nullptr, wxID_ANY, "Calculator UI Draft", wxPoint(100, 100), wxSize(335, 535)) {

	




	//Calculator Display
	//ok  so turns out hardcoding size is a really bad choice
	//i've made things so much worse for myself by doing that, and i hatemyself for thinking "oh it'll be easy, just make everything just like windows!"
	//truly i am a hinderence to my own self.
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	ButtonFactory buttonFactory;
	wxFont font(48, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_MAX, wxFONTWEIGHT_BOLD, false);
	// though, i do like how there is a right align, so i can at least kinda keep the windows 10 dream alive.
	CalculatorDisplay = new wxTextCtrl(panel, wxID_ANY, "",wxDefaultPosition,wxSize(335,75),wxTE_RIGHT);
	CalculatorDisplay->SetFont(font);
	CalculatorDisplay->Disable();
	
	//processor->SetBaseNumber(wxAtoi(CalculatorDisplay->GetLabel()));

	CalcBinDisplay = new wxTextCtrl(panel, 201, "Bin: "+ processor->GetBinary(), wxDefaultPosition, wxDefaultSize, wxTE_LEFT);
	CalcBinDisplay->Disable();
	CalcDecDisplay = new wxTextCtrl(panel, 202, "Dec: "+processor->GetDecimal(), wxDefaultPosition, wxDefaultSize, wxTE_LEFT);
	CalcDecDisplay->Disable();
	CalcHexDisplay = new wxTextCtrl(panel, 203, "Hex: "+processor->GetHexadecimal(), wxDefaultPosition, wxDefaultSize, wxTE_LEFT);
	CalcHexDisplay->Disable();

	keypadDigits = new wxButton * [10];
	//4x3 Matrix of numpad Keys, overloads are (Rows, Columns, vgap, hgap)
	// turns out the 0 key is really cringe to work with, so i'm making the matrix a 4x3, which is cringe i know but i have to do it.
	//*adendum, im doing something really stupid and im upping the grid size to 7x3
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

	//Keeping this "Stale Code" in comments just a as a contrast to how much nicer and easier to read this became.

	/*calcPlus = new wxButton(panel,30000,"+",wxDefaultPosition,wxSize(80,45));		
	calcMinus = new wxButton(panel, 30001, "-", wxDefaultPosition, wxSize(80, 45)); 
	calcMult = new wxButton(panel, 30002, "*", wxDefaultPosition, wxSize(80, 45));  
	calcDiv = new wxButton(panel, 30003, "/", wxDefaultPosition, wxSize(80, 45));	
	calcMod = new wxButton(panel, 30004, "%", wxDefaultPosition, wxSize(80, 45));	
	calcEqual = new wxButton(panel, 30005, "=", wxDefaultPosition, wxSize(80, 45)); 
	calcClear = new wxButton(panel, 30006, "C", wxDefaultPosition, wxSize(80, 45)); */

	calcPlus  =	buttonFactory.calcPlusButton(panel, keypadSizer);
	calcMinus = buttonFactory.calcMinusButton(panel, keypadSizer);
	calcMult  =	buttonFactory.calcMultButton(panel, keypadSizer);
	calcDiv   =	buttonFactory.calcDivButton(panel, keypadSizer);
	calcMod   =	buttonFactory.calcModButton(panel, keypadSizer);
	calcEqual = buttonFactory.calcEqualButton(panel, keypadSizer);
	calcClear = buttonFactory.calcClearButton(panel, keypadSizer);

	// I could probably consolidate this as well once i get the barebones stuff down.
	// Yep, consolidated all to "ButtonFactory.cpp" and "ButtonFactory.h"


	/*keypadSizer->Add(calcPlus, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcMinus, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcMult, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcDiv, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcMod, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcEqual, 1, wxEXPAND | wxALL);
	keypadSizer->Add(calcClear, 1, wxEXPAND | wxALL);*/

	

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

void CalcWindow::OnButtonClicked(wxCommandEvent& evt) {
	int evtID = evt.GetId();
	switch (evtID)
	{
	case 0: {
		CalculatorDisplay->AppendText("0");
		break;
	}
	case 1:{
		CalculatorDisplay->AppendText("1");
		break; 
	}
	case 2:{
		CalculatorDisplay->AppendText("2");
		break; 
	}
	case 3:{
		CalculatorDisplay->AppendText("3");
		break; 
	}
	case 4:{
		CalculatorDisplay->AppendText("4");
		break; 
	}
	case 5:{
		CalculatorDisplay->AppendText("5");
		break; 
	}
	case 6:{
		CalculatorDisplay->AppendText("6");
		break; 
	}
	case 7:{
		CalculatorDisplay->AppendText("7");
		break; 
	}
	case 8:{
		CalculatorDisplay->AppendText("8");
		break; 
	}
	case 9:{
		CalculatorDisplay->AppendText("9");
		break; 
	}
	case 30000: {
		CalculatorDisplay->AppendText("+");
		break;
	}
	case 30001: {
		CalculatorDisplay->AppendText("-");
		break;
	}
	case 30002: {
		CalculatorDisplay->AppendText("*");
		break;
	}
	case 30003: {
		CalculatorDisplay->AppendText("/");
		break;
	}
	case 30004: {
		CalculatorDisplay->AppendText("%");
		break;
	}
	case 30005: {

		std::string result = processor->calcProcessorEquals(CalculatorDisplay->GetValue());
		CalculatorDisplay->SetLabel(result);
		CalcBinDisplay->SetLabel(processor->GetBinary());
		CalcDecDisplay->SetLabel(processor->GetDecimal());
		CalcHexDisplay->SetLabel(processor->GetHexadecimal());
		break;
	}
	case 30006: {
		CalculatorDisplay->SetLabel(processor->calcProcessorClear());
		break;
	}
	default:
		break;
	}
	
}