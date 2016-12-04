#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	int P;
	cin >> P;

	while (P--)
	{
		int k;
		cin >> k;

		int total = 0;

		std::vector<int> heights;
		for (int n = 0; n < 20; ++n)
		{
			int i;
			cin >> i;

			size_t j = 0;
			for (; j < heights.size(); ++j)
			{
				if (i < heights[j])
				{ 
					break;
				}
			}
			
			total += heights.size() - j;
			heights.push_back(i);
			std::sort(heights.begin(), heights.end());
		}

		cout << k << " " << total << endl;
	}
	return 0;
}
