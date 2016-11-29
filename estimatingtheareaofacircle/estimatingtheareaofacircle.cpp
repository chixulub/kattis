#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	double r,m,c;
	while(cin >> r >> m >> c)
	{
		if (r == 0 && m == 0 && c == 0) break;

		double real = 3.14159265359*r*r;
		double est = 4.0*r*r*(c/m);

		printf("%.10lf %.10lf\n", real, est);
	}
	return 0;
}
