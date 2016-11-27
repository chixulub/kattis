#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	float R = 0, C = 0;
	cin >> R >> C;
	float F = R-C;
	printf("%3.6f\n", 100*(F*F)/(R*R));
	return 0;
}
