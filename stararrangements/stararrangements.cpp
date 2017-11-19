#include <iostream>
#include <cstdint>
#include <cmath>
using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;
	cout << N << ":" << endl;

	for (int i = 2; i < N; ++i)
	{
		int row1 = i;
		int row2 = i-1;

		int firstRows = row1 + row2;

		int rest = N%firstRows;
		if (rest == 0 || rest == row1)
		{
			cout << row1 << "," << row2 << endl;
		}

		++firstRows;
		++row2;
		rest = N%firstRows;
		if (rest == 0 || rest == row1)
		{
			cout << row1 << "," << row2 << endl;
		}
	}
	return 0;
}
