#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	string garbage;
	cin >> N;

	while (N--)
	{
		getline(cin, garbage);
		int g, m;
		cin >> g >> m;

		int gmax = 0;
		int mmax = 0;

		while(g--)
		{
			int x;
			cin >> x;
			gmax = max(x, gmax);
		}
		while(m--)
		{
			int x;
			cin >> x;
			mmax = max(x, mmax);
		}

		if (mmax > gmax)
			cout << "MechaGodzilla" << endl;
		else
			cout << "Godzilla" << endl;
	}
	return 0;
}
