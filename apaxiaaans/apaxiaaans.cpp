#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	char answer[256] = {0};
	char* shortname = answer;
	std::string input;
	cin >> input;
	const char* longname = input.c_str();

	shortname[0] = longname[0];
	++longname;
	while(*longname)
	{
		if (*longname != *shortname)
		{
			++shortname;
			*shortname = *longname;
		}

		++longname;
	}

	cout << answer << endl;
	return 0;
}
