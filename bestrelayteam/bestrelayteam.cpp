#include <iostream>
#include <cstdint>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct Runner
 {
	string name;
	double first;
	double second;
};

bool operator == (Runner const& a, Runner const& b)
{
	return a.name == b.name;
}

bool operator < (Runner const& a, Runner const& b)
{
	return a.name < b.name;
}

ostream& operator << (ostream& os, Runner const& r)
{
	os << r.name << " - " << r.first << " - " << r.second;
	return os;
}

int main(int, char**)
{
	int N;
	cin >> N;

	list<Runner> runners;
	vector<Runner> best;

	while (N--)
	{
		Runner r;
		cin >> r.name >> r.first >> r.second;
		runners.push_back(r);
	}


	runners.sort([] (Runner const& a, Runner const& b) {
				return a.first < b.first;
			});

	auto it = runners.begin();
	for (int i = 0; i < 4; ++i)
	{
		best.push_back(*it);
		++it;
	}
	

	runners.sort([] (Runner const& a, Runner const& b) {
				return a.second < b.second;
			});

	it = runners.begin();
	while(best.size() < 8 && it != runners.end())
	{
		if (find(best.begin(), best.end(), *it) == best.end())
		{
			best.push_back(*it);
		}
		++it;
	}
	
	sort(best.begin(), best.end());

	double least = best[0].first + best[1].second + best[2].second + best[3].second;
	vector<Runner> dreamteam = best;
	while (next_permutation(best.begin(), best.end()))
	{
		double t =
			best[0].first + best[1].second + best[2].second + best[3].second;

		if (t < least)
		{
			least = t;
			dreamteam = best;
		}
	}

	cout << least << endl;
	for (int i = 0; i < 4; ++i) cout << dreamteam[i].name << endl;
	return 0;
}
