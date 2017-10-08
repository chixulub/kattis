#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int e, f, c;
	cin >> e >> f >> c;

	e+=f;

	int d = 0;
	while (e >= c)
	{
			e-=(c-1);
			++d;
	}

	cout << d << endl;
	return 0;
}
