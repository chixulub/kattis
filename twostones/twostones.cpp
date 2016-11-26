#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N = 0;
	cin >> N;
	cout << (N&1 ? "Alice" : "Bob") << endl;
	return 0;
}
