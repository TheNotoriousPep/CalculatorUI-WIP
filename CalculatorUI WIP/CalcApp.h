#pragma once
#include "wx/wx.h"

class CalcWindow;

class CalcApp : public wxApp
{
public:
	CalcApp();
	~CalcApp();


private:
	CalcWindow* calculatorWindow = nullptr;

public:
	virtual bool OnInit();
};

