#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

int main(int, char**)
{
	std::map<int, std::string> cups;

	int N = 0;
	cin >> N;

	int radius = 0;
	std::string color;
	std::string tmp;
	while(N--)
	{
		cin >> tmp;

		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			radius = std::stoi(tmp)/2;
			cin >> color;
		}
		else
		{
			color = tmp;
			cin >> radius;
		}

		cups[radius] = color;
	}

	for (auto it : cups)
	{
		cout << it.second << endl;
	}

	return 0;
}
