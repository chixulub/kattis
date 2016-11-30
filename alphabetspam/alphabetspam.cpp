#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int count[4] = {0};

	std::string line;
	cin >> line;

	for (char c : line)
	{
		if (c == '_')
		{
			++count[0];
		}
		else if (c >= 'a' && 'z' >= c)
		{
			++count[1];
		}
		else if (c >= 'A' && 'Z' >= c)
		{
			++count[2];
		}
		else
		{
			++count[3];
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		printf("%.7lf\n", double(count[i])/line.size());
	}

	return 0;
}
