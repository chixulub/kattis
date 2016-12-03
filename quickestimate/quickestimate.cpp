#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string line;
	int N;
	cin >> N;
	std::getline(cin, line);

	while (N--)
	{
		std::getline(cin, line);
		cout << line.length() << endl;
	}
	return 0;
}
