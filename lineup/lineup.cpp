#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;
	--N;
	bool inc = true;
	bool dec = true;
	std::string last;
	cin >> last;
	while(N-- && (inc || dec))
	{
		std::string current;
		cin >> current;

		inc &= (last < current);
		dec &= (current < last);

		last = current;
	}

	if (inc)
	{
		cout << "INCREASING" << endl;
	}
	else if (dec)
	{
		cout << "DECREASING" << endl;
	}
	else
	{
		cout << "NEITHER" << endl;
	}
	return 0;
}
