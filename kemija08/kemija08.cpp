#include <iostream>
#include <cstdint>

using namespace std;

inline bool isWovel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int, char**)
{
	std::string sentence;
	std::getline(cin, sentence);

	const char* letter = sentence.c_str();
	while(*letter)
	{
		cout << *letter;
		letter += 1 + 2*isWovel(*letter);
	}

	cout << endl;

	return 0;
}
