#pragma once
#include <string>
#include "IBaseCommand.h"
class Multiply : public IBaseCommand
{
private:
	std::string _input1;
	std::string _input2;
public:


	void SetInputs(std::string input1, std::string input2) {
		_input1 = input1;
		_input2 = input2;
	}

	std::string calcProcessorMultiply(std::string input1, std::string input2) {
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		std::string result = std::to_string(math1 * math2);
		return result;
	}

	std::string Execute() {
		std::string result = "";
		result = calcProcessorMultiply(_input1, _input2);
		return result;
	}
};

