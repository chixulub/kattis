#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	const char* day[7] = {"Thursday", "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday"};
	int offset[] = {0,31,59,90,120,151,181,212,243,273,304,334};
	int D, M;

	cin >> D >> M;

	cout << day[(offset[M-1]+D-1)%7] << endl;
	return 0;
}
