#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N, won = 0;
	cin >> N;

	while(N--)
	{
		string battle;
		cin >> battle;
		won += (battle.find("CD") == string::npos);
	}

	cout << won << endl;

	return 0;
}
