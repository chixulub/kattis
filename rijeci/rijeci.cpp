#include <iostream>
#include <cstdint>


using namespace std;

int main(int, char**)
{
	int numA[46] = {0};
	int numB[46] = {0};
	numA[0] = 1;

	for (int i = 1; i <= 45; ++i)
	{
		numA[i] = numB[i-1];
		numB[i] = numB[i-1] + numA[i-1];
	}

	int k = 0;
	cin >> k;

	cout << numA[k] << " " << numB[k] << endl;
	return 0;
}
