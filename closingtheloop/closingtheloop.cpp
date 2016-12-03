#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	int testcase = 0;
	while (N--)
	{
		++testcase;

		std::vector<int> red;
		std::vector<int> blue;

		int S;
		cin >>S;

		while (S--)
		{
			int l;
			char c;

			cin >> l >> c;

			if (c == 'R')
			{
				red.push_back(l);
			}
			else
			{
				blue.push_back(l);
			}
		}

		int n = min(red.size(), blue.size());

		int L = 0;

		std::sort(red.begin(), red.end());
		std::reverse(red.begin(), red.end());
		std::sort(blue.begin(), blue.end());
		std::reverse(blue.begin(), blue.end());

		for (int i = 0; i < n; ++i)
		{
			L += (red[i] + blue[i]);
		}

		cout << "Case #" << testcase << ": " << L - 2*n << endl;
	}

	return 0;
}
