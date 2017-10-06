#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N, M=2;
	cin >> N;


	while(N--) M += M-1;

	cout << M*M << endl;

	return 0;
}
