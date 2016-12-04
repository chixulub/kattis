#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

struct Rectangle
{
	float x0,x1,y0,y1;
};

struct Circle
{
	float x, y, r;
};

int main(int, char**)
{
	int m;
	cin >> m;

	std::vector<Rectangle> rectangles;
	std::vector<Circle> circles;
	while (m--)
	{
		std::string shape;
		cin >> shape;

		if (shape == "rectangle")
		{
			Rectangle r;
			cin >> r.x0 >> r.y0 >> r.x1 >> r.y1;
			rectangles.push_back(r);
		}
		else
		{
			Circle c;
			cin >> c.x >> c.y >> c.r;
			c.r *= c.r;
			circles.push_back(c);
		}
	}

	int n;
	cin >> n;
	while (n--)
	{
		float x,y;
		cin >> x >> y;
		
		int count = 0;

		for (auto& r : rectangles)
		{
			count += (r.x0 <= x && r.x1 >= x && r.y0 <= y && r.y1 >= y);
		}

		for (auto& c : circles)
		{
			float dx = c.x - x;
			float dy = c.y - y;

			count += (dx*dx+dy*dy <= c.r);
		}

		cout << count << endl;
	}
	return 0;
}
