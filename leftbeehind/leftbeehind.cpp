#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int x, y;

	while (cin >> x >> y && (x+y))
	{
		if (x+y == 13)
		{
			cout << "Never speak again." << endl;
		}
		else if (x ==y)
		{
			cout << "Undecided." << endl;
		}
		else if (x < y)
		{
			cout << "Left beehind." << endl;
		}
		else
		{
			cout << "To the convention." << endl;
		}
	}

	return 0;
}
