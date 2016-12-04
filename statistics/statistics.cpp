#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int testcase = 0;
	int N = 0;
	while (cin >> N)
	{
		cout << "Case " << ++testcase << ": ";

		int minimum =  1000000;
		int maximum = -1000000;
		for (int i = 0; i < N; ++i)
		{
			int n;
			cin >> n;

			minimum = min(n, minimum);
			maximum = max(n, maximum);
		}

		cout << minimum << " " << maximum << " " << (maximum - minimum) << endl;
	}

	return 0;
}
