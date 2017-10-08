#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int r, n;
	cin >> r >> n;

	bool booked[101] = {false};

	while (n--)
	{
		int s;
		cin >> s;
		booked[s] = true;
	}

	for (int i = 1; i <= r; ++i)
	{
		if (!booked[i])
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << "too late" << endl;

	return 0;
}
