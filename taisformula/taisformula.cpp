#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;

	uint32_t t0, t1;
	double v0, v1;

	cin >> t0 >> v0;

	double total = 0;

	--N;
	while(N-->0)
	{
		cin >> t1 >> v1;

		total += 0.5*(v0+v1)*(t1-t0);

		t0 = t1;
		v0 = v1;
	}

	printf("%.5f\n", total/1000.0);

	return 0;
}
