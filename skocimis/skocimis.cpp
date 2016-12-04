#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << max(b-a, c-b) - 1 << endl;
	return 0;
}
