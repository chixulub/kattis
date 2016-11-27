#include <iostream>
#include <cstdint>
#include <set>

using namespace std;

int main(int, char**)
{
	int T = 0;
	cin >> T;
	while(T--)
	{
		int N = 0;
		cin >> N;

		std::set<std::string> names;
		std::string name;
		while (N--)
		{
			cin >> name;
			names.insert(name);
		}

		cout << names.size() << endl;
	}
	return 0;
}
