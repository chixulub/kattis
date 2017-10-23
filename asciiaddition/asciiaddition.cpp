#include <iostream>
#include <cstdint>
#include <cstring>
#include <list>
using namespace std;

struct Token
{
	char line[7][5];

	Token(
			const char* l0,
			const char* l1,
			const char* l2,
			const char* l3,
			const char* l4,
			const char* l5,
			const char* l6)
	{
		memcpy(line[0], l0, 5);
		memcpy(line[1], l1, 5);
		memcpy(line[2], l2, 5);
		memcpy(line[3], l3, 5);
		memcpy(line[4], l4, 5);
		memcpy(line[5], l5, 5);
		memcpy(line[6], l6, 5);
	}

	bool operator == (Token const& other)
	{
		for (int row = 0; row < 7; ++row)
		{
			for (int col = 0; col < 5; ++col)
			{
				if (line[row][col] != other.line[row][col])
				{
					return false;
				}
			}
		}

		return true;
	}
};

ostream& operator << (ostream& os, Token const& tok)
{
	for (int i = 0; i < 7; ++i)
	{
		os << string(tok.line[i], 5) << endl;
	}

	return os;
}

Token tokens[11] = {
	{
		"xxxxx",
		"x...x",
		"x...x",
		"x...x",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"xxxxx",
		"x....",
		"x....",
		"xxxxx"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	},
	{
		"x...x",
		"x...x",
		"x...x",
		"xxxxx",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"x....",
		"x....",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	},
	{
		"xxxxx",
		"x....",
		"x....",
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"xxxxx",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x",
		"....x"
	},
	{
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx"
	},
	{
		"xxxxx",
		"x...x",
		"x...x",
		"xxxxx",
		"....x",
		"....x",
		"xxxxx"
	},
	{
		".....",
		"..x..",
		"..x..",
		"xxxxx",
		"..x..",
		"..x..",
		"....."
	}
};

int main(int, char**)
{
	string input[7];

	for (int i = 0; i < 7; ++i)
	{
		cin >> input[i];
	}

	size_t start = 0;
	int numTokens = 0;
	uint64_t a = 0, b = 0;
	uint64_t *num = &a;
	while (start < input[0].length())
	{

		Token tok(
				&input[0][start],
				&input[1][start],
				&input[2][start],
				&input[3][start],
				&input[4][start],
				&input[5][start],
				&input[6][start]);
		
		start += 6;
		++numTokens;

		if (tokens[10] == tok)
		{
			num = &b;
			continue;
		}

		for (int i = 0; i < 10; ++i)
		{
			if (tokens[i] == tok)
			{
				*num = (*num)*10 + i;
			}
		}
	}

	uint64_t result = a+b;
	
	list<int> digits;

	while (result)
	{
		digits.push_front(result%10);
		result/=10;
	}

	if (digits.size() == 0)
	{
		cout << tokens[0];
		return 0;
	}

	for (int line = 0; line < 7; ++line)
	{
		string delim = "";

		for (auto d : digits)
		{
			cout << delim << string(tokens[d].line[line],5);
			delim = ".";
		}
		cout << endl;
	}

	return 0;
}
