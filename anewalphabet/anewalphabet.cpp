#include <iostream>
#include <cstdint>

using namespace std;

#define DEF(tok, str)

const char* token[] = {
	"@",
	"8",
	"(",
	"|)",
	"3",
	"#",
	"6",
	"[-]",
	"|",
	"_|",
	"|<",
	"1",
	"[]\\/[]",
	"[]\\[]",
	"0",
	"|D",
	"(,)",
	"|Z",
	"$",
	"']['",
	"|_|",
	"\\/",
	"\\/\\/",
	"}{",
	"`/",
	"2"
};

int main(int, char**)
{
	std::string str;
	std::getline(cin, str);

	for (char c : str)
	{
		int m = c | 32;

		if (m >= 'a' && m <= 'z')
		{
			printf("%s", token[m-'a']);
		}
		else
		{
			printf("%c", c);
		}
	}

	printf("\n");

	return 0;
}
