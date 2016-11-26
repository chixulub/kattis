#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int a = 0;
		cin >> a;

		int p = a % 10;
		int x = a / 10;
		int y = 1;
		while(p--)
		{
			y *= x;
		}

		sum += y;
	}

	cout << sum << endl;
	return 0;
}
