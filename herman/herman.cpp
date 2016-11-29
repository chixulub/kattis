#include <iostream>
#include <cstdint>

/*
   x+y=r
   y = r-x
 */
using namespace std;

int main(int, char**)
{
	double R = 0;
	cin >> R;

	printf("%.6lf\n%.6lf\n", 3.14159265359*R*R, 2.0*R*R);
	return 0;
}
