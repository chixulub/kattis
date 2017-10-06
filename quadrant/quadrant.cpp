#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int x, y;
	cin >> x >> y;
	int q[4] = {1,4,2,3};
	cout << q[2*(x<0) + (y<0)] << endl;

	return 0;
}
