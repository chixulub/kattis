#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int n, p, q;
	cin >> n >> p >> q;

	int s = (p+q) % (2*n);

	cout << ((s<n) ? "paul" : "opponent") << endl;
	return 0;
}
