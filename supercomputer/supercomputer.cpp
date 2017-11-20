#include <iostream>
#include <cstdint>
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;

template<typename T = int32_t>
struct PrefixTree
{
	std::vector<T> m_mem;
	uint32_t m_N;

	PrefixTree(uint32_t size)
	: m_mem(minPowerOfTwo(size)*2)
	, m_N(minPowerOfTwo(size))
	{
	}

	void put(int pos, T newValue)
	{
		pos += m_N;
		T diff = newValue - m_mem[pos];

		while (pos)
		{
			m_mem[pos] += diff;
			pos /= 2;
		}
	}

	T value(uint32_t pos) const
	{
		return m_mem[pos + m_N];
	}

	T prefix(int pos) const
	{
		pos += m_N;
		T surplus = 0;
		uint32_t from = pos+1;
		pos /= 2;
		while (pos)
		{
			if (from&1)
			{
				surplus += m_mem[from];
			}

			from = pos+1;
			pos /= 2;
		}

	    return m_mem[0] - surplus;
	}

private:
	inline uint32_t minPowerOfTwo(uint32_t i) const
	{
		uint32_t n = 1;
		while (n < i)
		{
			n*=2;
		}

		return n;
	}
};
    
int main(int, char**)
{
    int n, K;
    char op;
	uint32_t a, b;
    scanf("%d %d", &n, &K);

	auto* tree = new PrefixTree<int32_t>(n);

    while (K--)
    {
        scanf("\n%c %u", &op, &a);
        if (op == 'C')
        {
            scanf(" %u", &b);
            printf("%d\n", tree->prefix(b) - tree->prefix(a-1));
        }
		else
        {
			int32_t newValue = 1 - tree->value(a);
			tree->put(a, newValue);
        }
    }

    return 0;
}
