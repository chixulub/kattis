#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int player, N, t, T = 0;
	char a;
	cin >> player >> N;
	--player;
	while(N--)
	{
		cin >> t >> a;

		T += t;

		if(T >= 3*60+30)
		{
			cout << (player%8)+1 << endl;
			break;
		}

		player += (a=='T');
	}

	return 0;
}
