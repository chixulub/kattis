#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		int M, g, gNext;
		cin >> M >> g;

		bool found = false;
		for (int pos = 2; pos < M+1; ++pos)
		{
			cin >> gNext;

			if (gNext != g+1)
			{
				if (!found)
				{
					cout << pos << endl;
					found = true;
				}
			}

			g = gNext;
		}
	}

	return 0;
}
