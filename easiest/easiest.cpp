#include <iostream>
#include <cstdint>

using namespace std;

inline int digitSum(int n)
{
	int sum = 0;
	while(n)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main(int, char**)
{
	int N = 0;
	while(cin >> N)
	{
		if (N == 0) break;

		int nSum = digitSum(N);

		for (int i = 11; i <= 100; ++i)
		{
			if (digitSum(N*i) == nSum)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
