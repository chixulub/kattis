#include <iostream>
#include <cstdint>

using namespace std;

int decodeCard(string const& card)
{
	int s0 = card[0] == '1' ? 1 : (card[0] == '2' ? 2 : 4);
	int s1 = card[1] == 'D' ? 1 : (card[1] == 'S' ? 2 : 4);
	int s2 = card[2] == 'S' ? 1 : (card[2] == 'T' ? 2 : 4);
	int s3 = card[3] == 'R' ? 1 : (card[3] == 'G' ? 2 : 4);
	
	return s0 | (s1 << 3) | (s2 << 6) | (s3 << 9);
}

bool isSet(int c0, int c1, int c2)
{
	int c = c0|c1|c2;

	for (int i = 0; i < 4; ++i)
	{
		switch (c & 7)
		{
			case 1:
			case 2:
			case 4:
			case 7:
				break;
			default: return false;
		}

		c >>= 3;
	}

	return true;
}

int main(int, char**)
{

	int card[12] = {0};

	for (int i = 0; i < 12; ++i)
	{
		string cardStr;
		cin >> cardStr;
		card[i] = decodeCard(cardStr);
	}

	bool found = false;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = i+1; j < 11; ++j)
		{
			for (int k = j+1; k < 12; ++k)
			{
				if (isSet(card[i], card[j], card[k]))
				{
					printf("%d %d %d\n", i+1, j+1, k+1);
					found = true;
				}
			}
		}
	}

	if (!found)
	{
		cout << "no sets" << endl;
	}

	return 0;
}
