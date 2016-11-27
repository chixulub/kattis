#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int T = 0;
	cin >> T;

	while(T--)
	{
		int last = 0;
		cin >> last;
		int current;
		int import = 0;
		while(cin >> current)
		{
			if (current == 0)
			{
				cout << import << endl;
				break;
			}

			int extra = current - 2*last;
			if (extra > 0)
			{
				import += extra;
			}
			last = current;
		}
	}
	return 0;
}
