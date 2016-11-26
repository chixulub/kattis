#include <iostream>
#include <cstdint>
#include <map>
#include <set>

using namespace std;

int main(int, char**)
{
	int N = 0, M = 0;
	cin >> N >> M;

	std::map<int, int> sumMap;

	int maxCount = 0;
	for (int n = 1; n <= N; ++n)
	{
		for (int m = 1; m <= M; ++m)
		{
			int sum = n+m;
			int count = (sumMap[sum] += 1);

			maxCount = std::max(count, maxCount);
		}
	}

	std::set<int> maxSet;

	for (auto it : sumMap)
	{
		if(it.second == maxCount)
		{
			maxSet.insert(it.first);
		}
	}

	for (auto i : maxSet)
	{
		cout << i << endl;
	}

	return 0;
}
