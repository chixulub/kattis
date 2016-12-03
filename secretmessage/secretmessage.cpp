#include <iostream>
#include <cstdint>
#include <cmath>
#include <string.h>

using namespace std;

int main(int, char**)
{
	int N;
	std::string message;
	cin >> N;
	std::getline(cin, message);

	while (N--)
	{
		std::getline(cin, message);

		int n = sqrt(message.length());
		n += (n*n < message.length());

		char m[n][n];
		char* p = &m[0][0];

		memcpy(p, &message[0], message.length());
		memset(&p[message.length()], '*', n*n-message.length());

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				char c = m[n-j-1][i];
				if (c != '*')
				{
					cout << c;
				}
			}
		}
		cout << endl;

	}

	return 0;
}
