#include <iostream>
#include <cstdint>

using namespace std;

const std::string needle = "welcome to code jam";

int count(std::string const& stack)
{
	const auto slen = stack.length();
	const auto nlen = needle.length();
	uint32_t counter[needle.length()][stack.length()];
	std::fill_n((uint32_t*)counter, nlen*slen, 0);

	for (size_t si = 0; si < slen; ++si)
	{
		if (stack[si] == needle[0])
		{
			counter[0][si] = 1;
		}
	}


	for (size_t i = 0; i < nlen-1; ++i)
	{
		char c = needle[i];
		char n = needle[i+1];

		for (size_t j = i; j < slen; ++j)
		{
			if (stack[j] == c)
			{
				for (size_t k = j+1; k < slen; ++k)
				{
					if (stack[k] == n)
					{
						counter[i+1][k] = (counter[i+1][k] + counter[i][j]) % 10000;
					}
				}
			}
		}
	}

	int total = 0;

	for (int i = 0; i < slen; ++i)
	{
		total = (total + counter[nlen-1][i]) % 10000;
	}

	return total;
}

int main(int, char**)
{
	int T;
	cin >> T;
	std::string slask;
	std::getline(cin, slask);

	for (int testcase = 1; testcase <= T; ++testcase)
	{
		std::string line;
		std::getline(cin, line);

		printf("Case #%d: %.4d\n", testcase, count(line.c_str()));
	}

	return 0;
}
