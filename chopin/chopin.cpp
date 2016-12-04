#include <iostream>
#include <cstdint>
#include <map>

using namespace std;

int main(int, char**)
{
	std::map<std::string, std::string> noteMap;

#define DEF(x, y) noteMap[x] = y; noteMap[y] = x
	DEF("A#", "Bb");
	DEF("C#","Db");
	DEF("D#","Eb");
	DEF("F#","Gb");
	DEF("G#","Ab");

	std::string note, tonality;

	int testcase = 1;
	while (cin >> note >> tonality)
	{
		cout << "Case " << testcase++ << ": ";
		if (noteMap.count(note))
		{
			cout << noteMap[note] << " " << tonality << endl;
		}
		else
		{
			cout << "UNIQUE" << endl;
		}
	}
	return 0;
}
