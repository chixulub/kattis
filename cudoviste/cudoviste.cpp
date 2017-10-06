#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int R, C;
	cin >> R >> C;

	char* parking = new char[R*C];
#define GET(r,c) parking[(r)*C + (c)]

	for (int i = 0; i < R*C; ++i)
	{
		cin >> parking[i];
	}

	int count[5] = {0};
	for (int r = 0; r < R-1; ++r)
	{
		for (int c = 0; c < C-1; ++c)
		{
			int n = 0;
			if (
					(GET(r,   c)   != '#') &&
					(GET(r+1, c)   != '#') &&
					(GET(r,   c+1) != '#') &&
					(GET(r+1, c+1) != '#'))
			{


				n += GET(r,   c)   == 'X';
				n += GET(r+1, c)   == 'X';
				n += GET(r,   c+1) == 'X';
				n += GET(r+1, c+1) == 'X';

				++count[n];
			}
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << count[i] << endl;
	}

	return 0;
}
