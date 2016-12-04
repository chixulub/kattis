#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

int main(int, char**)
{
	std::string line;
	cin >> line;

	std::map<char, int> counts;
	for (char c : line)
	{
		counts[c] += 1;
	}

	int odds = 0;
	for (auto& count : counts)
	{
		odds += (count.second & 1);
	}

	cout << max(0, odds-1) << endl;

	return 0;
}
