#include <iostream>
#include <utility>

using namespace std;

std::pair<unsigned,unsigned> info(unsigned a, unsigned b)
{
	if (a+b > 2)
	{
		auto parent = (a<b) ? info(a,b-a) : info(a-b, b);

		return std::make_pair(parent.first + 1, parent.second*2 + (b<a));
	}

	
	return std::make_pair(0u,0u);;
}

int main(int, char**)
{
	int P,k,a,b;
	char slask;
	
	cin >> P;
	while (P--)
	{
		cin >> k >> a >> slask >> b;

		auto i = info(a,b);

		cout << k << " " << i.second + (1 << i.first) << endl;
	}
	return 0;
}
