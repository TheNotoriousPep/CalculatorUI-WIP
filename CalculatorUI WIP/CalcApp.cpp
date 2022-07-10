#include "CalcApp.h"
#include "CalcWindow.h"

wxIMPLEMENT_APP(CalcApp);

CalcApp::CalcApp() {

}

CalcApp::~CalcApp() {

}

bool CalcApp::OnInit() {
	calculatorWindow = new CalcWindow();
	calculatorWindow->Show();
	return true;
}