#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;
	std::string discard;
	std::getline(cin,discard);

	while (N--)
	{
		std::string a,b;
		std::getline(cin, a);
		std::getline(cin, b);

		cout << a << endl;
		cout << b << endl;
		for (size_t i = 0; i < a.size(); ++i)
		{
			cout << ((a[i] == b[i]) ? '.' : '*');
		}
		cout << endl << endl;
	}
	return 0;
}
