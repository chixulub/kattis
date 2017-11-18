#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int, char**)
{
	int n, x, p = 1, h = 0;

	cin >> n;

	std::vector<int> v;
	v.reserve(n);

	while(n--)
	{
		cin >> x;
		v.push_back(x);
	}

	std::sort(v.begin(), v.end());

	for (int i = (int)v.size()-1; i >= 0; --i)
	{
		h = max(p+v[i], h);
		++p;
	}

	cout << h+1 << endl;

	return 0;
}
