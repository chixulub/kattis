#include <iostream>
#include <cstdint>

using namespace std;

int digitSum(int n)
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
	int L = 0;
	int D = 0;
	int X = 0;
	cin >> L >> D >> X;

	for (int N = L; N <= D; ++N)
	{
		if (digitSum(N) == X)
		{
			cout << N << endl;
			L = N;
			break;
		}
	}
	
	for (int M = D; M >= L; --M)
	{
		if (digitSum(M) == X)
		{
			cout << M << endl;
			break;
		}
	}
	return 0;
}
