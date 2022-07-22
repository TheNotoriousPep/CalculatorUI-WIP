#include "pch.h"
#include "CppUnitTest.h"
#include "../CalculatorUI WIP/ButtonFactory.h"
//#include "../CalculatorUI WIP/ButtonFactory.cpp"
#include "../CalculatorUI WIP/CalculatorProcessor.h"
#include "wx/wx.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
namespace CalcAppUnitTests
{
	TEST_CLASS(CalcAppUnitTests)
	{
	public:
		
		//CalcProcessor Tests variables:
			CalcProcessor* processor = CalcProcessor::GetInstance();
			ButtonFactory button;
			wxTextCtrl* display = new wxTextCtrl();
			wxTextCtrl* binDisplay = new wxTextCtrl();
			wxTextCtrl* hexDisplay = new wxTextCtrl();
			wxTextCtrl* decDisplay = new wxTextCtrl();

			wxButton* calcAdd;
			wxButton* calcSubtract;
			wxButton* calcMultiply;
			wxButton* calcDivide;
			wxButton* calcModulo;
			wxButton* calcEquals;
			wxButton* calcClear;

			wxWindow* window = new wxWindow();
			wxGridSizer* grid = new wxGridSizer(7,3,0,0);
			std::string zerocheck = "NaN";
			std::string clearcheck = "";
			std::string label = "";
			int id = 0;
		TEST_METHOD(MultiplyTwoNumbers)
		{
			display->SetLabel("2*2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 4);
		}
		TEST_METHOD(DivideTwoNumbers)
		{
			display->SetLabel("2/2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 1);
		}
		TEST_METHOD(AddTwoNumbers)
		{
			display->SetLabel("2+2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 4);
		}
		TEST_METHOD(SubtractTwoNumbers)
		{
			display->SetLabel("2-2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 0);
		}
		TEST_METHOD(ModuloDivideTwoNumbers)
		{
			display->SetLabel("2%2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 0);
		}
		TEST_METHOD(DivideByZeroCheckOne)
		{
			display->SetLabel("2/0");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(result, zerocheck);
		}
		TEST_METHOD(ModuloByZeroCheckOne)
		{
			display->SetLabel("2%0");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(result, zerocheck);
		}
		TEST_METHOD(Input1Check)
		{
			display->SetLabel("2+0");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 2);
		}
		TEST_METHOD(Input2Check){
			display->SetLabel("0+2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), 2);
		}
		TEST_METHOD(DidIProperlyImplementNegatives) {
			display->SetLabel("0-2");
			std::string result = processor->calcProcessorEquals(display->GetLabel());
			Assert::AreEqual(stoi(result), -2);
		}
		TEST_METHOD(Clear) {
			display->SetLabel("0-2");
			std::string result = processor->calcProcessorClear();
			Assert::AreEqual(result, clearcheck);
		}
		//Cool! now time for the button checks ahahahahashahah how am i gonna do this.
		TEST_METHOD(AddButton)
		{
			calcAdd = button.calcPlusButton(window,grid);
			id = calcAdd->GetId();
			label = calcAdd->GetLabel();
			std::string labelcheck = "+";
			Assert::AreEqual(id, int(plus));
			Assert::AreEqual(label, labelcheck);

		}
		TEST_METHOD(MinusButton)
		{
			calcSubtract = button.calcMinusButton(window, grid);
			id = calcSubtract->GetId();
			label = calcSubtract->GetLabel();
			std::string labelcheck = "-";
			Assert::AreEqual(id, int(minus));
			Assert::AreEqual(label, labelcheck);

		}
		TEST_METHOD(MultButton)
		{
			calcMultiply = button.calcMultButton(window, grid);
			id = calcMultiply->GetId();
			label = calcMultiply->GetLabel();
			std::string labelcheck = "";
			Assert::AreEqual(id, int(mult));
			Assert::AreEqual(label, labelcheck);

		}
		TEST_METHOD(DivisionButton)
		{
			calcDivide = button.calcMinusButton(window, grid);
			id = calcDivide->GetId();
			label = calcDivide->GetLabel();
			std::string labelcheck = "/";
			Assert::AreEqual(id, int(divide));
			Assert::AreEqual(label, labelcheck);
		}
		TEST_METHOD(ModuloButton)
		{
			calcModulo = button.calcModButton(window, grid);
			id = calcModulo->GetId();
			label = calcModulo->GetLabel();
			std::string labelcheck = "%";
			Assert::AreEqual(id, int(mod));
			Assert::AreEqual(label, labelcheck);
		}
		TEST_METHOD(EqualsButton)
		{
			calcEquals = button.calcEqualButton(window, grid);
			id = calcEquals->GetId();
			label = calcEquals->GetLabel();
			std::string labelcheck = "=";
			Assert::AreEqual(id, int(equal));
			Assert::AreEqual(label, labelcheck);
		}
		TEST_METHOD(ClearButton)
		{
			calcClear = button.calcClearButton(window, grid);
			id = calcClear->GetId();
			label = calcClear->GetLabel();
			std::string labelcheck = "=";
			Assert::AreEqual(id, int(clear));
			Assert::AreEqual(label, labelcheck);
		}
		TEST_METHOD(BinCheck)
		{
			processor->SetBaseNumber(255);
			std::string result = processor->GetBinary();
			std::string bin = "0000000011111111";
			Assert::AreEqual(result, bin);
		}
		TEST_METHOD(DecCheck)
		{
			processor->SetBaseNumber(255);
			std::string result = processor->GetDecimal();
			std::string Dec = "255";
			Assert::AreEqual(result, Dec);
		}
		TEST_METHOD(HexCheck)
		{
			processor->SetBaseNumber(255);
			std::string result = processor->GetHexadecimal();
			std::string Hex = "0xff";
			Assert::AreEqual(result, Hex);
		}
	};
}
