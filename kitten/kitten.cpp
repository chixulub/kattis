#include <iostream>
#include <cstdint>
#include <map>
#include <sstream>

using namespace std;

int main(int, char**)
{
	map<int,int> parentOf;

	int k, p, b;
	string line;

	cin >> k;

	while (p != -1)
	{
		getline(cin, line);
		stringstream ss(line);

		ss >> p;
		if (p == -1)
		{
			break;
		}

		while (ss)
		{
			ss >> b;
			parentOf[b] = p;
		}
	}

	cout << k;
	while (parentOf.count(k))
	{
		k = parentOf[k];
		cout << " " << k;
	}

	cout << endl;

	return 0;
}
