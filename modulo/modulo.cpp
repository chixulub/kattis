#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

int main(int, char**)
{
	std::set<int> unique;

	int n = 0;
	while (cin >> n)
	{
		unique.insert(n % 42);
	}

	cout << unique.size() << endl;
	return 0;
}
