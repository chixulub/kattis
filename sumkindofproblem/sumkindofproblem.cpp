#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int slask;
	cin >> slask;

	int sumAll[10001] = {0};
	int sumOdd[10001] = {0};
	int sumEven[10001] = {0};
	
	for (int i = 1; i <= 10000; ++i)
	{
		sumAll[i]  = sumAll[i-1] + i;
		sumOdd[i]  = sumOdd[i-1] + 2*i - 1;
		sumEven[i] = sumEven[i-1] + 2*i;
	}

	int setnumber = 0;
	int N = 0;
	while(cin >> setnumber >> N)
	{
		cout << setnumber << " " << sumAll[N] << " " << sumOdd[N] << " " << sumEven[N] << endl;
	}
	return 0;
}
