#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{
	std::vector<int> num(4);
	for (int i = 0; i < 4; ++i)
	{
		cin >> num[i];
	}

	std::sort(num.begin(), num.end());

	cout << num[2]*num[0] << endl;

	return 0;
}
