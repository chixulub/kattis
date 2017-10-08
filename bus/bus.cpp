#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		unsigned k;
		cin >> k;
		cout << (1<<k)-1 << endl;
	}
	return 0;
}
