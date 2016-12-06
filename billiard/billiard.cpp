#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(int, char**)
{
	double a,b,s,m,n;
	while (cin >> a >> b >> s >> m >> n && a+b+s+m+n > 0)
	{
		double x = a*m;
		double y = b*n;
		double vel = sqrt(x*x+y*y)/s;
		double ang = atan2(y,x)*180.0f/3.14159265359;
	
		printf("%.2lf %.2lf\n", ang, vel);
	}

	return 0;
}
