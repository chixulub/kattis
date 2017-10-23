#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

double pi = 3.14159265359;
inline double deg2rad(double deg)
{
	return deg*pi/180.0;
}

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		double ang = deg2rad(90);
		double x = 0, y = 0;
		int m;
		cin >> m;

		while (m--)
		{
			double r, d;
			cin >> r >> d;
			ang += deg2rad(r);
			x += cos(ang)*d;
			y += sin(ang)*d;
		}

		printf("%.6lf %.6lf\n", x, y);
	}
	return 0;
}
