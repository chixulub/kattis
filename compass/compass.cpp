#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int n1 = 0, n2 = 0;
	cin >> n1 >> n2;

	n2 = (360 + (n2-n1)) % 360;
	n1 = 0;

	if (n2 <= 180)
	{
		cout << n2 << endl;
	}
	else
	{
		cout << n2 - 360 << endl;
	}

	return 0;
}
