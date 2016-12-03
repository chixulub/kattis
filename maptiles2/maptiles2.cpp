#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string quadkey;
	cin >> quadkey;

	int x = 0;
	int y = 0;

	for (char c : quadkey)
	{
		x*=2;
		y*=2;
		switch (c)
		{
			case '0': break;

			case '1': ++x; break;
			
			case '2': ++y; break;
			
			case '3': ++x; ++y; break;
		}
	}

	cout << quadkey.length() << " " << x << " " << y << endl;
	return 0;
}
