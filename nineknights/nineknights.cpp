#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

struct Point
{
	int x, y;
};

bool operator < (Point const& a, Point const& b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}


int main(int, char**)
{
	set<Point> occupied;

	int target[8][2] = 
	{
		{2,1},
		{1,2},
		{2,-1},
		{1,-2},
		{-2,1},
		{-1,2},
		{-2,-1},
		{-1,-2}
	};

	bool fail = false;
	char c;
	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < 5; ++x)
		{
			cin >> c;

			if (c == 'k')
			{
				Point p{x,y};

				for (int i = 0; i < 8; ++i)
				{

					Point q{x+target[i][0], y+target[i][1]};

					if (occupied.count(q))
					{
						fail = true;
					}
				}

				occupied.insert(p);
			}
		}
	}

	if (occupied.size() != 9)
		fail = true;
	cout << (fail ? "invalid" : "valid") << endl;
	return 0;
}
