#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Sieve
{
	std::vector<bool> m_mem;
	std::vector<int> m_primes;
	int m_N;

public:
	Sieve(int N)
		: m_mem(N)
		, m_N(N)
	{
		m_primes.reserve((double(N)/log(N))*(1 + 1.2762/log(N))); // over-estimate of pi(N).
		m_mem[0] = m_mem[1] = true;
		int iMax = sqrt(N);
		int i = 2;
		do
		{
			for (int j = i*i; j < N; j += i)
			{
				m_mem[j] = true;
			}

			while (m_mem[++i]);
		}
		while (i < iMax);

		for (int i = 2; i < N; ++i)
		{
			if (isPrime(i))
			{
				m_primes.push_back(i);
			}
		}
	}

	int maxNumber() const
	{
		return m_N-1;
	}

	bool isPrime(int n) const
	{
		return n < m_N && !m_mem[n];
	}

	std::vector<int> const& getPrimes() const
	{
		return m_primes;
	}
};

std::map<int,int> factorize(int n, Sieve const& sieve)
{
	std::map<int, int> fac;

	if (sieve.isPrime(n))
	{
		fac[n] = 1;
	}
	else
	{
		for (int p : sieve.getPrimes())
		{
			while (n%p == 0)
			{
				n /= p;
				++fac[p];
			}

			if (n == 1) break;
		}
	}

	if (n >= sieve.maxNumber())
	{
		fac[n]++;
	}

	return fac;
}

int main(int, char**)
{
	int N = 46341; // sqrt(2^31 -1) rounded up.

	Sieve s(N);

	int num;
	while (cin >> num)
	{
		if (num < 0)
		{
			cout << "-1 ";
			num = -num;
		}


		auto factors = factorize(num, s);

		string delim = "";
		for (auto f : factors)
		{
			cout << delim << f.first;
			if (f.second > 1)
			{
				cout << "^" << f.second;
			}
			delim = " ";
		}
		cout << endl;
	}

	return 0;
}
