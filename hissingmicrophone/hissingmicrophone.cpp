#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length()-1; ++i)
	{
		if (str[i] == 's' && str[i+1] == 's')
		{
			cout << "hiss" << endl;
			return 0;
		}
	}

	cout << "no hiss" << endl;

	return 0;
}
