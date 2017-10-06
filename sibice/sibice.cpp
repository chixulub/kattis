#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N, W, H, L, LL;
	cin >> N >> W >> H;
	LL = W*W + H*H;

	while(N--)
	{
		cin >> L;
		cout << (L*L <= LL ? "DA" : "NE") << endl;
	}
	return 0;
}
