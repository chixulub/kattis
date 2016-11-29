#include <iostream>
#include <cstdint>
#include <map>
#include <set>

using namespace std;

int main(int, char**)
{
	std::string deck;
	std::getline(cin, deck);

	std::map<char, std::set<int>> suiteMap;

	for (uint32_t i = 0; i < deck.size(); i += 3)
	{
		char suite = deck[i];
		int value = 10*(deck[i+1]-'0') + (deck[i+2]-'0');

		if (suiteMap[suite].count(value))
		{
			cout << "GRESKA" << endl;
			return 0;
		}

		suiteMap[suite].insert(value);
	}


	cout << 13 - suiteMap['P'].size() << " ";
	cout << 13 - suiteMap['K'].size() << " ";
	cout << 13 - suiteMap['H'].size() << " ";
	cout << 13 - suiteMap['T'].size() << endl;

	return 0;
}
