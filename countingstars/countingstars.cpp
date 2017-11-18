#include <iostream>
#include <vector>
#include <cstdint>
#include <queue>

using namespace std;

int h, w;
struct Point {
	int x, y;
};

inline bool valid(int x, int y)
{
	return x >= 0 && x < w && y >= 0 && y < h;
}

inline char& pixel(vector<char>& img, int x, int y)
{
	return img[y*w + x]; 
}

void fill(vector<char>& img, int x0, int y0)
{
	static Point offset[4] = {
		{1,0},
		{-1,0},
		{0,1},
		{0,-1}
	};

	queue<Point> q;
	q.push(Point{x0,y0});
	pixel(img, x0,y0) = '#';

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		if (valid(p.x+offset[i].x, p.y+offset[i].y))
		{
			char& c = pixel(img, p.x+offset[i].x, p.y+offset[i].y);;
			if (c == '-')
			{
				c = '#';
				q.push(Point{p.x+offset[i].x, p.y+offset[i].y});
			}
		}
	}
}

int countStars(vector<char>& img)
{
	int numStars = 0;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (pixel(img, x,y) == '-')
			{
				++numStars;
				fill(img, x,y);
			}
		}
	}

	return numStars;
}

int main(int, char**)
{
	vector<char> img;
	int caseId = 1;
	for (;cin >> h >> w; ++caseId)
	{
		string line;
		getline(cin,line);

		img.reserve(w*h);
		for (int y = 0; y < h; ++y)
		{
			getline(cin, line);
			for (int x = 0; x < w; ++x)
			{
				img[y*w + x] = line[x];
			}
		}

		cout << "Case " << caseId << ": " << countStars(img) << endl;
	}

	return 0;
}
