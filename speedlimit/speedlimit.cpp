#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	for (;;)
	{
		cin >> N;
		if (N == -1) break;
		int T = 0;
		int miles = 0;
		while(N--)
		{
			int speed = 0;
			int t = 0;
			cin >> speed >> t;
			t -= T;
			miles += speed * t;
			T += t;
		}

		cout << miles << " miles" << endl;
	}
	return 0;
}
