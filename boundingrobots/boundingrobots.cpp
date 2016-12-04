#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int w, l;

	while ((cin >> w >> l) && (w+l))
	{
		int u = 0, v = 0;
		int x = 0, y = 0;
		int n;
		cin >> n;

		while (n--)
		{
			char dir;
			int dist;

			cin >> dir >> dist;

			switch (dir)
			{
				case 'd': v-=dist; y-=dist; break;
				case 'u': v+=dist; y+=dist; break;
				case 'r': u+=dist; x+=dist; break;
				case 'l': u-=dist; x-=dist; break;
			}

			u = max(u, 0);
			u = min(u, w-1);
			v = max(v, 0);
			v = min(v, l-1);
		}

		cout << "Robot thinks " << x << " " << y << endl;
		cout << "Actually at " << u << " " << v << endl;
		cout << endl;
	}

	return 0;
}
