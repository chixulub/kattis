#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int l, r;
	cin >> l >> r;
	
	if (l+r)
	{
		cout << ((r!=l) ? "Odd " : "Even ") << 2*max(l,r) << endl;
	}
	else
	{
		cout << "Not a moose" << endl;
	}
	return 0;
}
