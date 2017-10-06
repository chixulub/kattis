#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int X, N, P, S=0;
	cin >> X >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P;
		S += P;
	}

	cout << X*(N+1) - S << endl;
	return 0;
}
