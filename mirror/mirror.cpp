#include <iostream>
#include <cstdint>
#include <list>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Test " << t << endl;
		int R = 10, C = 10;
		cin >> R >> C;
		std::list<std::string> lines;
		while (R--)
		{
			std::string line;
			std::getline(cin, line);
			if (line == "")
				std::getline(cin, line);
			std::reverse(line.begin(), line.end());
			lines.push_front(line);
			
		}

		for (auto& line : lines)
		{
			cout << line << endl;
		}
	}
	return 0;
}
