#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

double pi = 3.14159265359;

int main(int, char**)
{
	int D, V;

	while (cin >> D >> V)
	{
		if (D == 0 && V == 0) break;

		double v = V/2.0f;
		double R = D/2.0f;

		double r = pow(R*R*R - (3.0/2.0)*v/pi, 1.0/3.0);

		printf("%.8lf\n", 2.0*r);
	}

	return 0;
}
