#include "ButtonFactory.h"
#include "wx/wx.h"
#include "CalcApp.h"
#include "CalcWindow.h"


enum calcButtonIDs
{
	plus = 30000,
	minus,
	mult,
	divide,
	mod,
	equal,
	clear
};

ButtonFactory::ButtonFactory() {

}

ButtonFactory::~ButtonFactory() {

}

//i have come to the realization that this does NOT consolidate anything, and that i just redid the button thing, but i kinda know what to do next
//wxButton* createButton(wxWindow* buttonParent, int buttonID, std::string buttonLabel,  
//	const wxPoint &buttonPosition = wxDefaultPosition, const wxSize &buttonSize = wxSize(80,45)){
//	wxButton* newButton = new wxButton(buttonParent,buttonID,buttonLabel,buttonPosition,buttonSize);
//	return newButton;
//}

wxButton* ButtonFactory::calcPlusButton(wxWindow* parent, wxGridSizer* grid) {
	
	wxButton* plusButton = new wxButton(parent, plus, "+", wxDefaultPosition, wxSize(80, 45));
	grid->Add(plusButton, 1, wxEXPAND | wxALL);
	return plusButton;
}
wxButton* ButtonFactory::calcMinusButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* minusButton = new wxButton(parent, minus, "-", wxDefaultPosition, wxSize(80, 45));
	grid->Add(minusButton, 1, wxEXPAND | wxALL);
	return minusButton;
}
wxButton* ButtonFactory::calcMultButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* multButton = new wxButton(parent, mult, "*", wxDefaultPosition, wxSize(80, 45));
	grid->Add(multButton, 1, wxEXPAND | wxALL);
	return multButton;
}
wxButton* ButtonFactory::calcDivButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* divButton = new wxButton(parent, divide, "/", wxDefaultPosition, wxSize(80, 45));
	grid->Add(divButton, 1, wxEXPAND | wxALL);
	return divButton;
}
wxButton* ButtonFactory::calcModButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* modButton = new wxButton(parent, mod, "%", wxDefaultPosition, wxSize(80, 45));
	grid->Add(modButton, 1, wxEXPAND | wxALL);
	return modButton;
}
wxButton* ButtonFactory::calcEqualButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* equalButton = new wxButton(parent, equal, "=", wxDefaultPosition, wxSize(80, 45));
	grid->Add(equalButton, 1, wxEXPAND | wxALL);
	return equalButton;
}
wxButton* ButtonFactory::calcClearButton(wxWindow* parent, wxGridSizer* grid) {
	wxButton* clearButton = new wxButton(parent, clear, "C", wxDefaultPosition, wxSize(80, 45));
	grid->Add(clearButton, 1, wxEXPAND | wxALL);
	return clearButton;
}

