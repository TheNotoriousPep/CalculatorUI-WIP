#pragma once
#include "wx/wx.h"

class CalcWindow;

class CalcApp : public wxApp
{
	CalcWindow* calculatorWindow = nullptr;

public:
	virtual bool OnInit();
};

