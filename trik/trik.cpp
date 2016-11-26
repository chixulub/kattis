#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string moves;
	cin >> moves;

	int cup[3] = {1,0,0};
	for (char move : moves)
	{
		switch(move)
		{
			case 'A': std::swap(cup[0], cup[1]); break;
			case 'B': std::swap(cup[1], cup[2]); break;
			case 'C': std::swap(cup[0], cup[2]); break;
		}
	}

	int i = 0;
	for (;cup[i] != 1; ++i);

	cout << i+1 << endl;
	return 0;
}
