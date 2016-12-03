#include <iostream>
#include <cstdint>
#include <list>

using namespace std;

int main(int, char**)
{
	std::string line;
	std::list<std::string> lines;
	while (std::getline(cin, line))
	{
		lines.push_back(line);
	}

	int n = 0;
	for (auto& line : lines)
	{
		n = max(n, (int)line.length());
	}
	lines.pop_back();
	
	int penalty = 0;

	for (auto& line : lines)
	{
		int p = n - line.length();
		penalty += p*p;
	}

	cout << penalty << endl;

	return 0;
}
