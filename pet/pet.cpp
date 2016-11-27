#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int maxScore = 0;
	int maxPos = 0;

	for (int i = 1; i <= 5; ++i)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int score = a+b+c+d;
		if (score > maxScore)
		{
			maxScore = score;
			maxPos = i;
		}
	}

	cout << maxPos << " " << maxScore << endl;
	return 0;
}
