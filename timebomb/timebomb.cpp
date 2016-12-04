#include <iostream>
#include <cstdint>

std::string digit[10] = {
/*0*/ "**** ** ** ****",
/*1*/ "  *  *  *  *  *",
/*2*/ "***  *****  ***",
/*3*/ "***  ****  ****",
/*4*/ "* ** ****  *  *",
/*5*/ "****  ***  ****",
/*6*/ "****  **** ****",
/*7*/ "***  *  *  *  *",
/*8*/ "**** ***** ****",
/*9*/ "**** ****  ****"
};

using namespace std;

std::string symbols[8] = {
	"***************",
	"***************",
	"***************",
	"***************",
	"***************",
	"***************",
	"***************",
	"***************"
};

int main(int, char**)
{
	for (int n = 0; n < 5; ++n)
	{
		std::string line;
		std::getline(cin, line);

		for (int i = 0; i < line.length()+1; i += 4)
		{
			symbols[i/4][n*3+0] = line[i+0];
			symbols[i/4][n*3+1] = line[i+1];
			symbols[i/4][n*3+2] = line[i+2];
		}
	}


	int code = 0;
	for (int i = 0; i < 8; ++i)
	{
		int num = -1;
		for (int j = 0; j < 10; ++j)
		{
			if (symbols[i] == digit[j])
			{
				num = j;
				code = code*10 + j;
				break;
			}
		}

	}

	cout << ((code%6) ? "BOOM!!" : "BEER!!") << endl;

	return 0;
}
