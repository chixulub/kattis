#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	struct {
		int on, off, period;
	} dog[2];

	cin >> dog[0].on >> dog[0].off;
	dog[0].period = dog[0].on + dog[0].off;
	cin >> dog[1].on >> dog[1].off;
	dog[1].period = dog[1].on + dog[1].off;

	for (int i = 0; i < 3; ++i)
	{
		int minute;
		cin >> minute;
		--minute;

		int numDogs = 0;
		for (int j = 0; j < 2; ++j)
		{
			int m = minute % dog[j].period;
			numDogs += (m < dog[j].on);
		}

		const char* say[3] = 
		{
			"none",
			"one",
			"both"
		};

		cout << say[numDogs] << endl;

	}

	return 0;
}
