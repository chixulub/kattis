#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N, M;
	cin >> N >> M;

	int i = M-N;

	if ( i > 0)
	{
		cout << "Dr. Chaz will have " << i << " piece" << (i!=1 ? "s" : "") << " of chicken left over!" << endl;
	}
	else
	{
		cout << "Dr. Chaz needs " << -i << " more piece" << (i!=-1 ? "s" : "") << " of chicken!" << endl;
	}

	return 0;
}
