#include <iostream>
#include <string>
#include <algorithm>

std::string NumberToString(int number)
{
	char digit{ '1' };
	std::string strResult = "1";

	int mod;
	for (int i{}; i < 8; i++)
	{
		digit++;
		mod = number % 3;
		if (mod == 1)
			strResult.push_back('-');
		if (mod == 2)
			strResult.push_back('+');
		/*if (mod == 3)
			strResult.push_back('*');*/
		strResult.push_back(digit);
		number /= 3;
	}

	return strResult;
}

int StringToResult(std::string mathString)
{
	int intResult{};
	char sign{ '+' };

	int pos{};

	std::string strNumber = "";
	int intNumber;
	while (pos < mathString.length())
	{
		if (isdigit(mathString[pos]))
		{
			strNumber.push_back(mathString[pos]);
		}
		else
		{
			if (sign == '-')
				intResult -= std::stoi(strNumber);
			else
				intResult += std::stoi(strNumber);
			sign = mathString[pos];
			strNumber = "";
		}
		pos++;
	}
	if (sign == '-')
		intResult -= std::stoi(strNumber);
	else
		intResult += std::stoi(strNumber);

	return intResult;
}

int main()
{
	int amountTemplate{ 100 };

	std::string strResult;
	int intResult;

	for (int number{}; number < pow(4, 8); number++)
	{
		strResult = NumberToString(number);
		//std::cout << strResult << " = " << StringToResult(strResult) << "\n";
		intResult = StringToResult(strResult);
		if (intResult == amountTemplate)
			std::cout << strResult << " = " << intResult << "\n";
	}
}
