#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

int main(int, char**)
{
	int time;
	std::string problem;
	std::string status;

	int numCorrect = 0;
	int totalTime = 0;

	std::map<std::string, int> failCount;

	while (cin >> time >> problem >> status)
	{
		if (status == "right")
		{
			numCorrect += 1;
			totalTime += time;
			totalTime += 20 * failCount[problem];
		}
		else
		{
			failCount[problem] += 1;
		}
	}

	cout << numCorrect << " " << totalTime << endl;
	return 0;
}
