#include <iostream>
#include <cstdint>


// BEGIN LIB/sieve.h

#include <vector>
const int maxPrimeCandidate = 10000000; 
uint32_t largestPrime = 2;

uint32_t nextPrime(uint32_t i);
void initSieve();

// END LIB/sieve.h

using namespace std;


int main(int, char**)
{
	initSieve();

	uint32_t x;
	cin >> x;

	uint32_t k = 0;
	uint32_t p = 0;
	while (x > 1 && (p = nextPrime(p)))
	{
		while (x % p == 0)
		{
			x /= p;
			++k;
		}
	}

	if (x != 1)
	{
		++k;
	}

	cout << k << endl;

	return 0;
}

// BEGIN LIB/sieve.cpp

std::vector<bool> sieve(maxPrimeCandidate+1, 0);

uint32_t nextPrime(uint32_t i)
{
	while (i <= largestPrime && sieve[++i]);

	return i > largestPrime ? 0 : i;
}

void initSieve()
{
	sieve[0] = sieve[1] = 1;
	
	int i = 2;
	while (i <= maxPrimeCandidate)
	{
		if(!sieve[i])
		{

			largestPrime = i;

			int j = 2*i;
			while (j <= maxPrimeCandidate+1)
			{
				sieve[j] = 1;
				j+=i;
			}
		}

		++i;
	}
}

// END LIB/sieve.cpp
