#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main(int, char**)
{
	long double a;
	cin >> a;
	printf("%.9llf\n", 4.0*sqrt(a));

	return 0;
}
