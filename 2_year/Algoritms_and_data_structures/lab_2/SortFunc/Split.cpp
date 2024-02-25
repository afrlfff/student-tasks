#include <iostream>
#include <vector>

std::vector<std::string> Split(std::string str, char simb)
{
	std::string tmp = "";
	std::vector<std::string> result;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == simb || i == (str.size() - 1))
		{
			result.push_back(tmp + str[i]);
			tmp = "";
		}
		else
		{
			tmp += str[i];
		}
	}
	return result;
}