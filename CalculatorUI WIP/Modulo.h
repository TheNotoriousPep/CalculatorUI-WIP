#pragma once
#include <string>
#include "IBaseCommand.h"
class Modulo : public IBaseCommand
{
private:
	std::string _input1;
	std::string _input2;
public:


	void SetInputs(std::string input1, std::string input2) {
		_input1 = input1;
		_input2 = input2;
	}

	std::string calcProcessorModulo(std::string input1, std::string input2) {
		std::string result = "";
		int math1 = std::stoi(input1);
		int math2 = std::stoi(input2);
		if (math2 != 0)
		{
			result = std::to_string(math1 % math2);
		}
		else
		{
			result = "NaN";
		}

		return result;
	}

	std::string Execute() {
		std::string result = "";
		result = calcProcessorModulo(_input1, _input2);
		return result;
	}
};

