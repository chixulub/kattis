#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	while(cin >> N)
	{
		for (int i = 1; i <= N; ++i)
		{
			cout << i << " Abracadabra" << endl;
		}
	}
	return 0;
}
