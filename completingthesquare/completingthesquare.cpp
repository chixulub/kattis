#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

struct vec
{
	int x, y;
};

bool operator < (vec const& a, vec const& b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}

	return a.x < b.x;
}

vec operator - (vec const& a, vec const& b)
{
	return vec{a.x-b.x, a.y-b.y};
}

int dot(vec const& a, vec const& b)
{
	return a.x * b.x + a.y * b.y;
}

int main(int, char**)
{

	vector<vec> points;
	for (int i = 0; i < 3; ++i)
	{
		int x,y;
		cin >> x >> y;
		points.push_back(vec{x,y});
	}

	sort(points.begin(), points.end());

	while (next_permutation(points.begin(), points.end()))
	{
		vec u = points[1] - points[0];
		vec v = points[2] - points[0];

		if (dot(u,v) == 0)
		{
			cout << points[0].x + u.x + v.x << " " << points[0].y + u.y + v.y << endl;
			return 0;
		}
	}

	return 0;
}
