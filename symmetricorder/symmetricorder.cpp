#include <iostream>
#include <cstdint>
#include <list>

using namespace std;

int main(int, char**)
{
	int N = 0;
	int SET = 1;

	while (cin >> N)
	{
		if (N == 0) break;

		cout << "SET " << SET++ << endl;

		std::list<std::string> names;
		std::string name;
		for (int i = 1; i <= N; ++i)
		{
			cin >> name;

			if (i&1)
			{
				cout << name << endl;
			}
			else
			{
				names.push_front(name);
			}
		}

		for (auto& n : names)
		{
			cout << n << endl;
		}
	}
	return 0;
}
