#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	vector<int> n;
	n.resize(3);
	cin >> n[0] >> n[1] >> n[2];
	sort(n.begin(), n.end());

	int a = n[1]-n[0];
	int b = n[2]-n[1];

	if (a == b)
	{
		cout << n[2]+a << endl;
	}
	else if (a < b)
	{
		cout << n[1]+a << endl;
	}
	else
	{
		cout << n[0]+b << endl;
	}
	return 0;
}
