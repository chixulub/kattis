#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

struct Elem
{
	int val;
	int pos;
};

inline bool operator < (const Elem& a, const Elem& b)
{
	return a.val < b.val;
}

int main(int, char**)
{
	int n;
	string delim = "";
	while (cin >> n && n != 0)
	{
		std::vector<Elem> clean(n);
		std::vector<int> dirty(n);

		int tmp = n;
		int num;

		for (int i = 0; i < n; ++i)
		{
			cin >> clean[i].val;
			clean[i].pos = i;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> dirty[i];
		}

		std::sort(clean.begin(), clean.end());
		std::sort(dirty.begin(), dirty.end());

		std::vector<int> target(n);

		for (int i = 0; i < n; ++i)
		{
			target[clean[i].pos] = dirty[i];
		}

		cout << delim;
		for (int t : target)
		{
			cout << t << endl;
		}

		delim = "\n";
	}
	return 0;
}
