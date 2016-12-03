#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(int, char**)
{
	double x0, x1, y0, y1, p;

	while (cin >> x0 >> y0 >> x1 >> y1 >> p)
	{
		double dx = abs(x1-x0);
		double dy = abs(y1-y0);

		printf("%.10lf\n", pow(pow(dx,p)+pow(dy,p), 1.0/p));

	}

	return 0;
}
