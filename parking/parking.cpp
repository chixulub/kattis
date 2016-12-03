#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int cost[4] = {0};
	int minute[101] = {0};

	cin >> cost[1] >> cost[2] >> cost[3];

	for (int i = 0; i < 3; ++i)
	{
		int a, b;
		cin >> a >> b;

		for (int j = a; j < b; ++j)
		{
			++minute[j];
		}
	}

	int amount = 0;
	for (int m : minute)
	{
		amount += m*cost[m]; 
	}

	cout << amount << endl;
	return 0;
}
