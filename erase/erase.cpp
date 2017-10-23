#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	bool expected = !(N&1);

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); ++i)
	{
		if (expected != (a[i] == b[i]))
		{
			cout << "Deletion failed" << endl;
			return 0;
		}
	}

	cout << "Deletion succeeded" << endl;
	return 0;
}
