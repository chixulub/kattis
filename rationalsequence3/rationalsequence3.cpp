#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	uint32_t numSets, setIndex, k;
	cin >> numSets;

	while (numSets--)
	{
		cin >> setIndex >> k;

		uint32_t pow2 = 1;
		uint32_t l = 0;

		while (pow2*2 <= k)
		{
			pow2 *= 2;
			++l;
		}

		uint32_t n = k - pow2;
		uint32_t p = 1, q = 1;

		while (l--)
		{
			bool b = (n>>l)&1;

			if (b)
			{
				p += q;
			}
			else
			{
				q += p;
			}
		}
		cout << setIndex << " " << p << "/" << q << endl;



	}
	return 0;
}
