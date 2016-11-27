#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int n = 0;
	cin >> n;
	int m = 0;

	while(n)
	{
		m = (m << 1) | n & 1;
		n = n >> 1;
	}

	cout << m << endl;
	return 0;
}
