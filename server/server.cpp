#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int n, T;
	cin >> n >> T;

	int passed = 0;
	while (n--)
	{
		int t;
		cin >> t;

		T -= t;

		if (T < 0)
			break;

		++passed;

	}

	cout << passed << endl;
	return 0;
}
