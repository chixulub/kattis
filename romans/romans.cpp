#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main(int, char**)
{
	double miles;
	cin >> miles;

	miles *= 5280000.0;
	miles /= 4854.0;

	cout << (int)round(miles) << endl;
	return 0;
}
