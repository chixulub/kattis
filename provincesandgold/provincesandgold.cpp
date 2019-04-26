#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int g,s,c;
	cin >> g >> s >> c;

	int sum = 3*g + 2*s + c;
	
	if (sum >= 8)
	{
		cout << "Province or ";
	}
	else if (sum >= 5)
	{
		cout << "Duchy or ";
	}
	else if (sum >= 2)
	{
		cout << "Estate or ";
	}

	if (sum >= 6)
	{
		cout << "Gold" << endl;
	}
	else if (sum >= 3)
	{
		cout << "Silver" << endl;
	}
	else
	{
		cout << "Copper" << endl;
	}

	return 0;
}
