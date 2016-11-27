#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int c = 0;
	int t = 0;
	int g = 0;
	std::string cards;
	cin >> cards;

	for (char card : cards)
	{
		c += (card == 'C');
		t += (card == 'T');
		g += (card == 'G');
	}

	cout << c*c + t*t + g*g + 7*min(c,min(t,g)) << endl;
	return 0;
}
