#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int n;
	cin >> n;

	while(n--)
	{
		int r, e, c;
		cin >> r >> e >> c;

		e -= c;
		
		if (r < e)
		{
			cout << "advertise" << endl;
		}
		else if (e < r)
		{
			cout << "do not advertise" << endl;
		}
		else
		{
			cout << "does not matter" << endl;
		}
	}
	return 0;
}
