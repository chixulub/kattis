#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main(int, char**)
{
	double r, x, y;

	while (cin >> r >> x >> y)
	{
		double d = sqrt(x*x+y*y)/r;

		if (d >= 1.0f)
		{
			cout << "miss" << endl;
			continue;
		}

		double a = acos(d);

		double pi = 3.14159265649;
		double A = r*r;
		double p = sqrt(1.0f-d*d)*d*r*r;
		printf("%.6f %.6f\n", A*(pi-a) + p, A*a - p);


	}

	return 0;
}
