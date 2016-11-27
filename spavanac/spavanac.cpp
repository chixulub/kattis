#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int h = 0, m = 0;
	cin >> h >> m;

	int timestamp = m + 60*h;
	timestamp -= 45;
	if (timestamp < 0)
	{
		timestamp += 24*60;
	}

	cout << (timestamp / 60) << " " << (timestamp % 60) << endl;
	return 0;
}
