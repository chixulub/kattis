#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{

	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;

	std::string op = "";
	if (x+y == z)
	{
		op = "+=";
	}
	else if (x-y == z)
	{
		op = "-=";
	}
	else if (x*y == z)
	{
		op = "*=";
	}
	else if (x == y+z)
	{
		op = "=+";
	}
	else if (x == y-z)
	{
		op = "=-";
	}
	else if (x == y*z)
	{
		op = "=*";
	}
	else
	{
		int w = x/y;
		if (w == z && x == w*y)
		{
			op = "/=";
		}
		else
		{
			op = "=/";
		}
	}

	cout << x << op[0] << y << op[1] << z << endl; 
	return 0;
}
