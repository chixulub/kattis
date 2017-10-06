#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	string names;
	cin >> names;
	for (char c : names)
	{
		if (!(c & 32)) cout << c;
	}
	cout << endl;
	return 0;
}
