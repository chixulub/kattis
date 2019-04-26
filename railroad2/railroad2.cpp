#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int x, y;
	cin >> x >> y;

	cout << (y&1 ? "impossible" : "possible") << endl;
	return 0;
}
