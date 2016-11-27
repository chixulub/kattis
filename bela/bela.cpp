#include <iostream>
#include <cstdint>

int cardValue(char c, bool dominant)
{
	switch (c)
	{
		case 'A': return 11;
		case 'K': return 4;
		case 'Q': return 3;
		case 'J': return dominant ? 20 : 2;
		case 'T': return 10;
		case '9': return dominant ? 14 : 0;
		default: return 0;
	}
}

using namespace std;

int main(int, char**)
{
	int N = 0;
	std::string dominant;
	std::string card;
	cin >> N >> dominant;
	N *= 4;
	
	int score = 0;

	while(N--)
	{
		cin >> card;
		score += cardValue(card[0], card[1] == dominant[0]);
	}

	cout << score << endl;
	return 0;
}
