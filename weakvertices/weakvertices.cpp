#include <iostream>
#include <cstdint>
#include <set>
#include <vector>
using namespace std;

int main(int, char**)
{
	int n;

	while (cin >> n && n != -1)
	{
		std::vector<uint32_t> edgeMap(n,0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				uint32_t edge;
				cin >> edge;
				edgeMap[i] |= (edge << j);
			}
		}
		
		std::set<int> weakSet;
		for (int i = 0; i < n; ++i)
		{
			uint32_t myEdges = edgeMap[i];
			bool weak = true;
			for (int j = 0; j < n; ++j)
			{
				if (myEdges & (1 << j))
				{
					if (myEdges & edgeMap[j])
					{
						weak = false;
						break;
					}
				}
			}

			if (weak)
			{
				weakSet.insert(i);
			}
		}

		std::string delim = "";
		for (int w : weakSet)
		{
			cout << delim << w;
			delim = " ";
		}
		cout << endl;
	}

	return 0;
}
