#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		std::string message;
		cin >> message;

		int n = sqrt(message.length());

		for (int col = n-1; col >= 0; --col)
		{
			for (int row = 0; row < n; ++row)
			{
				cout << message[n*row + col];
			}
		}

		cout << endl;
	}

	return 0;
}
