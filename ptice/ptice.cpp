#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

char adrian(int n)
{
	return 'A' + n%3;
}

char bruno(int n)
{
	switch (n%4)
	{
		case 1: return 'A';
		case 3: return 'C';
		default: return 'B';
	}
}

char goran(int n)
{
	switch ((n/2)%3)
	{
		case 0: return 'C';
		case 1: return 'A';
		case 2: return 'B';
	}
}

int main(int, char**)
{
	int best = 0;
	std::map<std::string, int> scoreMap;

	int slask = 0;
	cin >> slask;

	std::string answers;
	cin >> answers;

	int i = 0;
	for (auto c : answers)
	{
		best = std::max(best, scoreMap["Adrian"] += (c == adrian(i)));
		best = std::max(best, scoreMap["Bruno"] += (c == bruno(i)));
		best = std::max(best, scoreMap["Goran"] += (c == goran(i)));
		++i;
	}

	cout << best << endl;
	for (auto it : scoreMap)
	{
		if (it.second == best)
		{
			cout << it.first << endl;
		}
	}

	return 0;
}
