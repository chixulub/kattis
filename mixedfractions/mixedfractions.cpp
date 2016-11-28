#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int a = 0, b = 0;

	while((cin >> a >> b) && !(a==0 && b==0))
	{
		cout << (a/b) << " " << (a%b) << " / " << b << endl;
	}
	return 0;
}
