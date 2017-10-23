#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main(int, char**)
{

	vector<int> n(3);
	cin >> n[0] >> n[1] >> n[2];
	sort(n.begin(), n.end());

	string order;
	cin >> order;

	cout << n[order[0]-'A'] << " " << n[order[1]-'A'] << " " << n[order[2]-'A'] << endl;
	return 0;
}
