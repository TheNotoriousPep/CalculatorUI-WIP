#pragma once
#include <string>
#include <sstream>
#include "CalcWindow.h"
#include <vector>

enum calcButtonIDs
{
	plus = 0,
	minus,
	mult,
	divide,
};

class CalcProcessor
{
private:
	CalcProcessor(){
		
	};
	static CalcProcessor* _calcProcessor;
	int baseNumber;
public:
	static CalcProcessor* GetInstance() {

		if (_calcProcessor == nullptr)
		{
			_calcProcessor = new CalcProcessor();
		}
		return _calcProcessor;
	}

	void SetBaseNumber(int num) {
		baseNumber = num;
	}


	CalcProcessor(CalcProcessor& other) = delete;
	void operator=(const CalcProcessor& other) = delete;

	std::string GetDecimal() {
		return std::to_string(baseNumber);
	}

	std::string GetHexadecimal() {
		
		wxString toHex = "0x"+wxString::Format(wxT("%02x"), baseNumber);
		std::string hexstring = std::string(toHex.mb_str());
		return hexstring;
	}
	/*
	PORTIONS OF THIS HEADER FILE WERE ADAPTED FROM THE FOLLOWING SOURCES:
	https://wiki.wxwidgets.org/Converting_everything_to_and_from_wxString

	Adapted from a forum post on Wxwidgets.org, from the user Doublemax on December 11th, 2010.
	https://forums.wxwidgets.org/viewtopic.php?t=29609

	*/
	std::string GetBinary() {
		std::string bin = "";
		int num = baseNumber;
		for (int i = 0; i < 16; i++)
		{
			if (num % 2 == 0)
			{
				bin = "0" + bin;
			}
			else
			{
				bin = "1" + bin;
			}
			num = num / 2;
		}

		return bin;
	}

	std::string calcProcessorAdd(std::string input1, std::string input2) {
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		std::string result = std::to_string(math1 + math2);
		return result;
		
	}

	std::string calcProcessorSubtract(std::string input1, std::string input2) {
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		std::string result = std::to_string(math1 - math2);
		return result;
	}

	std::string calcProcessorMultiply(std::string input1, std::string input2) {
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		std::string result = std::to_string(math1 * math2);
		return result;
	}

	std::string calcProcessorDivide(std::string input1, std::string input2) {
		std::string result = "";
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		if (math1 != 0 && math2 != 0)
		{
			result = std::to_string(math1 / math2);
		}
		else
		{
			result = "CANNOT DIVIDE BY ZERO, CLEAR ME NOW.";
		}
		
		return result;
	}

	std::string calcProcessorEquals(wxString calcDisplay) {
		
		int delimID = 0;
		std::string delim[] = { "+","-","*","/" };
		std::string input1, input2 = "";
		std::string result = "";
		std::vector<std::string> temp;
		//switch
		

		//We get the CalculatorDisplay string using CalculatorDisplay->GetLabel();,
		//which should look something like this:
		// 255+198
		//we convert that wxString into a normal string.
		std::string parsedString = std::string(calcDisplay.mb_str());
		std::string token = "";
		size_t pos = 0;
		// we then separate the two inputs, as input1 and input 2 as strings respectively, the previous calc functions conver to integers.
		// use the previous functions to get the math and the result, then return that result as a string that updates the CalculatorDisplay.
		for (size_t i = 0; i < 4; i++)
		{
			while ((pos = parsedString.find(delim[i])) != std::string::npos)
			{
				delimID = i;
				token = parsedString.substr(0, pos);
				temp.push_back(token);
				parsedString.erase(0, pos + delim[i].length());
			}
		}
		input1 = temp[0];
		input2 = parsedString;
		// I had  to adapt some of the code for this from this post by Vincenzo Pii, on January 10th 2013 on this Stackoverflow forum: 
		//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
		//I haven't even tested to see if this works but conceptually it sounds like it should separate the two strings to their respective inputs
			switch (delimID)
			{
			case 0: {
				result = calcProcessorAdd(input1, input2);
				break;
			}
			case 1: {
				result = calcProcessorSubtract(input1, input2);
				break;
			}
			case 2: {
				result = calcProcessorMultiply(input1, input2);
				break;
			}
			case 3: {
				result = calcProcessorDivide(input1, input2);
				break;
			}
			default:
				break;
			}
		
		SetBaseNumber(std::stoi(result));
		return result;
	}

	std::string calcProcessorClear() {
		std::string clear = "";
		return clear;
	}
	
};

//c++ why are you so cringe sometimes. even had the prof stumped on this one, with this cringe linker error. smh my head.
//so the cpp file wasnt needed??? thats wild man.
CalcProcessor* CalcProcessor::_calcProcessor = nullptr;