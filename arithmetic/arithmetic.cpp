#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

string b8;
string b16;
int pos8;
int pos16;
char tmpBuf[4] = {0};

int init()
{
	cin >> b8;
	b16.resize(b8.length()+4);
	pos8  = int(b8.length()-1);
	pos16 = int(b16.length());
}

bool hasNext()
{
	return pos8 >= 0;
}

int next()
{
	char c = '0';

	if (hasNext())
	{
		c = b8[pos8--];
	}

	int n = int(c-'0');
	return n;
}

int read8()
{
	int num = 0;
	int b = 1;
	for (int i = 0; i < 4; ++i)
	{
		num += next() * b;
		b*=8;
	}

	return num;
}

void write16(int i)
{
	int n = 0;

	if (hasNext())
	{
		n = sprintf(tmpBuf, "%.3X", i);
	}
	else
	{
		n = sprintf(tmpBuf, "%X", i);
	}

	pos16-=n;

	memcpy(&b16[pos16], tmpBuf, n);
}

int main(int, char**)
{
	init();

	while (hasNext())
	{
		write16(read8());
	}

	auto p = b16.find_first_not_of('\0');
	cout << b16.substr(p) << endl;

    return 0;
}
