#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;
	while (N--)
	{
		float v0, theta, x1, h1, h2;
		cin >> v0 >> theta >> x1 >> h1 >> h2;
		float a = theta*3.141592f/180.0f;

		float t = x1/(v0*cos(a));
		float y = t*v0*sin(a) - 0.5f*9.81f*t*t;

		if (y >= h1+1 && y <= h2-1)
		{
			cout << "Safe" << endl;
		}
		else
		{
			cout << "Not Safe" << endl;
		}
	}
	return 0;
}
