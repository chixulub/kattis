#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;

		int minimum = 99;
		int maximum = 0;
		while (n--)
		{
			int i;
			cin >> i;
			minimum = min(i, minimum);
			maximum = max(i, maximum);
		}

		cout << 2*(maximum-minimum) << endl;
	}
	return 0;
}
