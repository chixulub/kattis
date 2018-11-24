#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int i;
	cin >> i;

	if (i < 3)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << (i-2) << endl;
	}

	return 0;
}
