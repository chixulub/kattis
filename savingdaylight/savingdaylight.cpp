#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string month, day, year;
	int uh,um, dh,dm;
	char slask;

	while (cin >> month >> day >> year >> uh >> slask >> um >> dh >> slask >> dm)
	{
		int up = uh*60+um;
		int down = dh*60+dm;
		int span = down-up;

		cout << month << " " << day << " " << year << " " << span/60 << " hours " << span%60 << " minutes" << endl;
	}
	return 0;
}
