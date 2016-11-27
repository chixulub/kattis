#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main(int, char**)
{
	// h/l = sin(a)
	// h = l*sin(a)
	// l = h/sin(a)

	float h = 0;
	float a = 0;

	cin >> h >> a;

	float l = h/sin(a*3.141592f/180.0f);
	int il = floor(l);
	if (il < l)
	{
		il += 1;
	}
	cout << il << endl;
	return 0;
}
