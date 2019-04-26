#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	while (N-->0)
	{
		double b, p;
		cin >> b >> p;

		double lowest = 60/(p/(b-1));
		double bpm = 60*b/p;
		double highest = 60/(p/(b+1));

		printf("%.4f %.4f %.4f\n", lowest, bpm, highest);
	}

	return 0;
}
