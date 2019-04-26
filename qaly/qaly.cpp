#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	double sum = 0;
	while (N-->0)
	{
		double q, y;
		cin >> q >> y;

		sum += q*y;
	}

	printf("%.3f\n", sum);

	return 0;
}
