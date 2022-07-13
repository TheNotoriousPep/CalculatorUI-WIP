#pragma once
#include "wx/wx.h"
#include "CalcWindow.h"
#include "CalcApp.h"
class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();

	
	

	wxButton* calcPlusButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcMinusButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcMultButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcDivButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcModButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcEqualButton(wxWindow* parent, wxGridSizer* grid);
	wxButton* calcClearButton(wxWindow* parent, wxGridSizer* grid);
	
};

