#include <iostream>
#include <cstdint>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main(int, char**)
{
	std::string line;

	while (std::getline(cin, line))
	{
		std::stringstream ss(line);

		std::vector<int> marks;
		std::map<int, int> numbers;
		int i;
		int greatest = 0;
		while (ss >> i)
		{
			for (auto m : marks)
			{
				++numbers[abs(i-m)];
			}
			greatest = max(i, greatest);
			marks.push_back(i);
		}

		std::set<int> missing;
		bool faulty = false;

		for (int i = 1; i <= greatest && !faulty; ++i)
		{
			switch (numbers[i])
			{
				case 0:
					missing.insert(i);
					break;
				case 1: 
					break;
				default:
						faulty = true;
						break;
			}
		}

		if (faulty)
		{
			cout << "not a ruler" << endl;
		}
		else if (missing.size())
		{
			cout << "missing";
			for (int i : missing)
			{
				cout << " " << i;
			}
			cout << endl;
		}
		else
		{
			cout << "perfect" << endl;
		}
	}
	return 0;
}
