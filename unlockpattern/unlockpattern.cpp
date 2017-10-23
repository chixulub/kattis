#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>

using namespace std;

struct vec
{
	double x, y;
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

ostream& operator << (ostream& os, vec const& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}

double dot(vec const& a, vec const& b)
{
	return a.x * b.x + a.y * b.y;
}

int main(int, char**)
{
	string line[3];
	getline(cin, line[0]);
	getline(cin, line[1]);
	getline(cin, line[2]);

	vector<vec> pos(10);
	for (int y = 0; y < 3; ++y)
	{
		int pad = 0;
		for (int x = 0; x < 3; ++x)
		{
			char character = line[y][x+pad];
			++pad;
			int c = character-'0';

			pos[c] = vec{double(x),double(y)};
		}
	}
	pos[0] = pos[1];

	double dist = 0;
	for (int i = 1; i < 10; ++i)
	{
		
		vec d = pos[i] - pos[i-1];
		double delta = sqrt(dot(d,d));
		dist += delta;
	}


	printf("%.10lf\n", dist);

	return 0;
}
