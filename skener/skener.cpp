#include <iostream>
#include <cstdint>
#include <sstream>

using namespace std;

int main(int, char**)
{
	int R = 0, C = 0, zR = 0, zC = 0;
	cin >> R >> C >> zR >> zC;

	while (R--)
	{
		std::string small;
		cin >> small;

		std::stringstream big;

		for (auto c : small)
		{
			for (int i = 0; i < zC; ++i)
			{
				big << c;
			}
		}

		for (int i = 0; i < zR; ++i)
		{
			cout << big.str() << endl;
		}
	}
	return 0;
}
