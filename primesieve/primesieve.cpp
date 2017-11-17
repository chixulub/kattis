#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
using namespace std;

int main(int, char**)
{
	int n, q, x, i = 2, numPrimes = 0;
	
	cin >> n >> q;

	int iMax = n+1;
	std::vector<bool> p(iMax, 0);
	p[0] = p[1] = 1;

	while (i < iMax)
	{
		if(!p[i])
		{
			++numPrimes;

			int j = 2*i;
			while (j <= iMax)
			{
				p[j] = 1;
				j+=i;
			}
		}

		++i;
	}

	cout << numPrimes << endl;

	while (q--)
	{
		cin >> x;
		cout << 1-p[x] << endl;
	}

	return 0;
}
