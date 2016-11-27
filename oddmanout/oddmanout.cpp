#include <iostream>
#include <cstdint>
#include <map>
using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;
	
	for (int n = 1; n <= N; ++n)
	{
		int G = 0;
		cin >> G;
		std::map<int,int> cMap;
		while (G--)
		{
			int C;
			cin >> C;
			cMap[C] += 1;
		}

		for (auto it : cMap)
		{
			if (it.second == 1)
			{
				cout << "Case #" << n << ": " << it.first << endl;
				break;
			}
		}
	}

	return 0;
}
