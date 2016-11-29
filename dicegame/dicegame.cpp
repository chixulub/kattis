#include <iostream>
#include <cstdint>

using namespace std;

float expected(int a, int b)
{
	int n = 1+b-a;
	int sum = n*a + (n*n + n)/2;

	return sum/float(n);
}

int main(int, char**)
{
	float exps[4];
	int a,b;

	for (int i = 0; i < 4; ++i)
	{
		cin >> a >> b;
		exps[i] = expected(a,b);
	}

	float gunnar = exps[0] + exps[1];
	float emma   = exps[2] + exps[3];

	if ( gunnar > emma)
	{
		cout << "Gunnar" << endl;
	}
	else if (emma > gunnar)
	{
		cout << "Emma" << endl;
	}
	else
	{
		cout << "Tie" << endl;
	}

	return 0;
}
