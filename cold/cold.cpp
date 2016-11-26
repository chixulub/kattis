#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;

	int count = 0;
	while(N--)
	{
		int i;
		cin >> i;
		if (i < 0)
		{
			++count;
		}
	}

	cout << count << endl;
	return 0;
}
