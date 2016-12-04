#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	double x, y;
	cin >> x >> y;

	if (x == 0 && y == 1)
	{
		cout << "ALL GOOD" << endl;
	}
	else if (y == 1)
	{
		cout << "IMPOSSIBLE" << endl;
	}
	else
	{
		double t = x/(1.0-y);
		printf("%.8lf\n", t);
	}

	return 0;
}
