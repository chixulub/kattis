#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

const char* table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

inline char rot(char c, int n)
{
	const char* foo = table;
	while(*foo != c)
	{
		++foo;
	}

	return *(foo+n);
}

int main(int, char**)
{
	int n = 0;
	while(cin >> n)
	{
		if (n == 0) break;

		std::string message;
		cin >> message;

		std::reverse(message.begin(), message.end());

		for (auto c : message)
		{
			cout << rot(c,n);
		}
		cout << endl;
	}
	return 0;
}
