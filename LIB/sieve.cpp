// BEGIN LIB/sieve.cpp

int largestPrime = 2;
std::vector<bool> sieve(maxPrimeCandidate+1, 0);

int nextPrime(int i)
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
