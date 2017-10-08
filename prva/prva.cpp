#include <iostream>
#include <cstdint>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int main(int, char**)
{
	int R,C;
	cin >> R >> C;

	std::vector<string> rows(R);
	std::vector<string> cols(C);

	for (auto& row : rows) row.resize(C);
	for (auto& col : cols) col.resize(R);

	char c;
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			cin >> c;
			if (c=='#') c = ' ';
			rows[row][col] = c;
			cols[col][row] = c;
		}
	}

	set<string> words;

	auto extractWords = [&words](string const& str)
	{
		stringstream ss(str);
		string word;
		while (ss >> word)
		{
			if (word.length() > 1)
			{
				words.insert(word);
			}
		}
	};
		
	for (auto& line : rows) extractWords(line);
	for (auto& line : cols) extractWords(line);

	cout << *words.begin() << endl;
	return 0;
}
