#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	uint64_t M,P,L,E,R,S,N;
	
	while (cin >> M >> P >> L >> E >> R >> S >> N)
	{
		while (N--)
		{
			uint64_t newEgg = M*E;
			uint64_t newPupa = L/R;
			uint64_t newMosquito = P/S;

			L = newEgg;
			P = newPupa;
			M = newMosquito;
		}

		cout << M << endl;
	}

	return 0;
}
