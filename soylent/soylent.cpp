#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int T = 0;
	cin >> T;

	while(T--)
	{
		int cals = 0;
		cin >> cals;

		cout << (cals / 400) + (cals % 400 != 0) << endl;
	}
	return 0;
}
