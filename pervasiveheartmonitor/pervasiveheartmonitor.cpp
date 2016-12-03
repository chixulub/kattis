#include <iostream>
#include <cstdint>
#include <sstream>

using namespace std;

int main(int, char**)
{
	std::string line;

	while (std::getline(cin, line))
	{
		std::stringstream ss(line);
		std::stringstream name;
		std::string delim = "";
		std::string token;

		double total = 0;
		int num = 0;

		while (ss >> token)
		{
			std::stringstream s(token);
			double f;
			if (s >> f)
			{
				total += f;
				++num;
			}
			else
			{
				name << delim << token;
				delim = " ";
			}
		}

		printf("%.6f %s\n", total/num, name.str().c_str());

	}
	return 0;
}
