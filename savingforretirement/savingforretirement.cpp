#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{

	int B, Br, Bs, A, As;
	cin >> B >> Br >> Bs >> A >> As;

	int Bt = 0, At = 0;

	while (B < Br)
	{
		++B;
		Bt += Bs;
	}

	while (Bt >= At)
	{
		++A;
		At += As;
	}

	cout << A << endl;

	return 0;
}
