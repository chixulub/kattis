#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	int num[9];
	int diff = -100;
	for (int i = 0; i < 9; ++i)
	{
		cin >> num[i];
		diff += num[i];
	}

	int i, j;
	bool done = false;
	for (i = 0; i < 8; ++i)
	{
		for (j = i+1; j < 9; ++j)
		{
			if (num[i] + num[j] == diff)
			{
				done = true;
				break;
			}
		}
		if (done) break;
	}

	for (int k = 0; k < 9; ++k)
	{
		if (k!=i && k!=j)
		{
			cout << num[k] << endl;
		}
	}

	return 0;
}
