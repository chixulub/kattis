#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	string A, B;
	cin >> A >> B;

	swap(A[0],A[2]);
	swap(B[0],B[2]);

	for (int i = 0; i < 3; ++i)
	{
		char a = A[i];
		char b = B[i];

		if (a > b)
		{
			cout << A << endl;
			break;
		}
		else if (b > a)
		{
			cout << B << endl;
			break;
		}
	}

	return 0;
}
