#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string line;
	int N;
	cin >> N;
	std::getline(cin, line);
	
	std::string simon = "Simon says";
	while (N--)
	{
		std::string line;
		std::getline(cin, line);
		if (line.substr(0, 10) == simon)
		{
			cout << line.substr(10) << endl;
		}
	}
	return 0;
}
