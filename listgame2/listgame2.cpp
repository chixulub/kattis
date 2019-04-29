#include <iostream>
#include <cstdint>


// BEGIN LIB/sieve.h

#include <vector>
#include <map>
#include <set>

const int maxPrimeCandidate = 32000000; 
uint64_t largestPrime = 2;

uint64_t nextPrime(uint64_t i);
void initSieve();

// END LIB/sieve.h

using namespace std;


int main(int, char**)
{
	initSieve();

	uint64_t x;
	cin >> x;

	uint64_t const input = x;
	cout << "input: " << x << endl;

	std::vector<uint64_t> primeFactors;

	uint64_t k = 0;
	uint64_t p = 0;
	while (x > 1 && (p = nextPrime(p)))
	{
		while (x % p == 0)
		{
			x /= p;
			++k;
			primeFactors.push_back(p);	
		}

		if (p > x)
		{
			break;
		}
	}

	
	if (x != 1)
	{
		primeFactors.push_back(x);	
		++k;
	}

	map<uint64_t, int> primeCount;	
	uint64_t r = 1;
	for (auto prime : primeFactors)
	{
		cout << "(" << prime << ")";
		r *= prime;
		++primeCount[prime];
	}
	cout << " = " << r << endl;

	
	set<uint64_t> numbers;

	for (auto& it : primeCount)
	{
		cout << it.first << ": " << it.second << endl;
		if (it.second == 1)
		{
			numbers.insert(it.first);
			it.second = 0;
		}
		else
		{
			int remaining = it.second;
			int currentPower = 0;
			uint64_t num = 1;
			while (remaining)
			{
				++currentPower;
				--remaining;
				num *= it.first;

				if (numbers.count(num) == 0)
				{
					numbers.insert(num);
					currentPower = 0;
					num = 1;
				}
			}

			it.second = currentPower;
		}
	}

	r = 1;
	for (auto num : numbers)
	{
		cout << "(" << num << ")";
		r *= num;
	}
	cout << " = " << r << endl;

	cout << "missing factor: " << (input/r) << endl;
	for (auto& it : primeCount)
	{
		cout << it.first << ": " << it.second << endl;
	}

	cout << "ANSWER: " << numbers.size() << endl;
	cout << "ANSWER: " << numbers.size() << endl;

	return 0;
}

// BEGIN LIB/sieve.cpp

std::vector<bool> sieve(maxPrimeCandidate+1, 0);

uint64_t nextPrime(uint64_t i)
{
	while (i <= largestPrime && sieve[++i]);

	return i > largestPrime ? 0 : i;
}

void initSieve()
{
	sieve[0] = sieve[1] = 1;
	
	uint64_t i = 2;
	while (i <= maxPrimeCandidate)
	{
		if(!sieve[i])
		{

			largestPrime = i;

			uint64_t j = 2*i;
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
