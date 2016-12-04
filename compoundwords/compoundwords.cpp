#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

int main(int, char**)
{
	std::string word;

	std::set<std::string> words, compounds;

	while (cin >> word)
	{
		for (auto const& w : words)
		{
			compounds.insert(w + word);
			compounds.insert(word + w);
		}

		words.insert(word);
	}

	for (auto const& w : compounds)
	{
		cout << w << endl;
	}

	return 0;
}
