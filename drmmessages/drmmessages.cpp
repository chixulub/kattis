#include <iostream>
#include <cstdint>

using namespace std;

char rotate(char c, int n)
{
	int C = c - 'A';

	return 'A' + char((c+n-'A')%(1+'Z'-'A'));
}

int main(int, char**)
{
	string str;
	cin >> str;

	int d = str.length()/2;
	int L = 0;
	int R = 0;
	for (int i = 0; i < d; ++i)
	{
		L += (str[i]-'A');
		R += (str[d+i]-'A');
	}

	for (int i = 0; i < d; ++i)
	{
		str[i]   = rotate(str[i], L);
		str[d+i] = rotate(str[d+i], R);
	}

	for (int i = 0; i < d; ++i)
	{
		str[i]   = rotate(str[i], str[d+i]-'A');
	}

	str[d] = '\0';

	cout << str.c_str() << endl;
	return 0;
}
