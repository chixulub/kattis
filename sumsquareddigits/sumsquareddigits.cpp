#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int P;
	cin >> P;

	while (P-->0)
	{
		uint32_t k, b, n, a, sum = 0;

		cin >> k >> b >> n;

		while (n)
		{
			a = n % b;
			n /= b;

			sum += a*a;
		}

		cout << k << " " << sum << endl;
	}

	return 0;
}
