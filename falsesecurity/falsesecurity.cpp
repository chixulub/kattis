#include <iostream>
#include <cstdint>
#include <map>
#include <sstream>
#include <list>

using namespace std;

int main(int, char**)
{
	std::map<char, std::string> codes;
	std::map<std::string, char> symbols;
#define FOO(symbol, code) codes[symbol] = code; symbols[code] = symbol;
	FOO('A', ".-")
	FOO('H', "....")
	FOO('O', "---")
	FOO('V', "...-")
	FOO('B', "-...")
	FOO('I', "..")
	FOO('P', ".--.")
	FOO('W', ".--")
	FOO('C', "-.-.")
	FOO('J', ".---")
	FOO('Q', "--.-")
	FOO('X', "-..-")
	FOO('D', "-..")
	FOO('K', "-.-")
	FOO('R', ".-.")
	FOO('Y', "-.--")
	FOO('E', ".")
	FOO('L', ".-..")
	FOO('S', "...")
	FOO('Z', "--..")
	FOO('F', "..-.")
	FOO('M', "--")
	FOO('T', "-")
	FOO('G', "--.")
	FOO('N', "-.")
	FOO('U', "..-")
	FOO('_', "..--")
	FOO('.', "---.")
	FOO(',', ".-.-")
	FOO('?', "----")

	std::string crypto;
	while (cin >> crypto)
	{
		std::stringstream ssMorse;
		std::list<int> lengths;
		for (char c: crypto)
		{
			ssMorse << codes[c];
			lengths.push_front(codes[c].length());
		}

		std::string str = ssMorse.str();
		const char* morse = str.c_str();

		int i = 0;
		for (int l : lengths)
		{
			std::string symCode(morse+i, l);
			i += l;

			cout << symbols[symCode];
		}

		cout << endl;
	}

	return 0;
}
