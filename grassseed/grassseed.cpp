#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	double C = 0;
	int L = 0;
	cin >> C >> L;

	double total = 0;
	while(L--)
	{
		double x = 0, y = 0;
		cin >> x >> y;
		total += x*y;
	}

	printf("%.7lf\n", total*C);
	return 0;
}
