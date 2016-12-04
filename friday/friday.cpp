#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int T;
	cin >> T;

	while (T--)
	{
		int days, months;
		cin >> days >> months;

		int count = 0;
		int weekday = 0;
		while (months--)
		{
			int daysInMonth;
			cin >> daysInMonth;

			count += ((daysInMonth >= 13) && (weekday == 0));

			weekday = (weekday + daysInMonth) % 7;
		}

		cout << count << endl;
	}

	return 0;
}
