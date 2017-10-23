#include <iostream>
#include <cstdint>
#include <list>

using namespace std;

list<int> calc(int n)
{
	list<int> pack;

	while (n)
	{
		int m = n;
		pack.push_front(n);
		while (m--)
		{
			int tmp = pack.back();
			pack.pop_back();
			pack.push_front(tmp);
		}

		--n;
	}

	return pack;
}

int main(int, char**)
{
	int N;
	cin >> N;

	while (N--)
	{
		int n;
		cin >> n;

		auto pack = calc(n);

		string delim = "";
		for (int card : pack)
		{
			cout << delim << card;
			delim = " ";
		}

		cout << endl;
	}
	return 0;
}
