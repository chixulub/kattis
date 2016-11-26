#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

int main(int, char**)
{
	int X[3];
	int Y[3];

	std::set<int> xSet;
	std::set<int> ySet;

	for (int i = 0; i < 3; ++i)
	{
		cin >> X[i] >> Y[i];
		xSet.insert(X[i]);
		ySet.insert(Y[i]);
	}

	for (int x : xSet)
	{
		for (int y : ySet)
		{
			bool found = false;
			for (int i = 0; i < 3; ++i)
			{
				if (X[i] == x && Y[i] == y)
				{
					found = true;
				}
			}

			if (!found)
			{
				cout << x << " " << y << endl;
				return 0;
			}
		}
	}

	return 0;
}
