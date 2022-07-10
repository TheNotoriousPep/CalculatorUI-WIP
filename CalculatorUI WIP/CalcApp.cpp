#include "CalcApp.h"
#include "CalcWindow.h"

wxIMPLEMENT_APP(CalcApp);

bool CalcApp::OnInit() {
	calculatorWindow = new CalcWindow();
	calculatorWindow->Show();
	return true;
}