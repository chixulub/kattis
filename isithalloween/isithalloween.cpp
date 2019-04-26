#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	string m;
	int d;

	cin >> m >> d;
	
	if ((m == "OCT" && d == 31) || (m == "DEC" && d == 25))
	{
		cout << "yup" << endl;
	}
	else
	{
		cout << "nope" << endl;
	}
	
	return 0;
}
