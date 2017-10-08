#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string stones;
	cin >> stones;

	int B = 0;
	int W = 0;

	for (char stone : stones)
	{
		B += (stone == 'B');
		W += (stone == 'W');
	}

	cout << (B==W) << endl;

	return 0;
}
