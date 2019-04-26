#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

int main(int, char**)
{
	map<char,int> ranks;

	for (int i = 0; i < 5; ++i)
	{
		string card;
		cin >> card;

		++ranks[card[0]];
	}

	int strength = 0;

	for (auto& r : ranks)
	{
		strength = max(strength, r.second);
	}

	cout << strength << endl;

	return 0;
}
