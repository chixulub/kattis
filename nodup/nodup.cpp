#include <iostream>
#include <cstdint>
#include<set>

using namespace std;

int main(int, char**)
{
	set<string> words;
	string str;
	while (cin >> str)
	{
		if (words.count(str))
		{
			cout << "no" << endl;
			return 0;
		}

		words.insert(str);
	}

	cout << "yes" << endl;
	return 0;
}
