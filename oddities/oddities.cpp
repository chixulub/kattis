#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;

	while(N--)
	{
		int x = 0;
		cin >> x;
		cout << x << " is " << (x&1 ? "odd" : "even") << endl;
	}
	return 0;
}
