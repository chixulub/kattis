#include <iostream>
#include <cstdint>
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;

template<typename T = int32_t>
struct PrefixTree
{
	uint32_t m_N;
	std::vector<T> m_mem;

	PrefixTree(uint32_t size)
	: m_mem(minPowerOf2(size)),
	, m_N(size)
	{
	}

	void put(int pos, T newValue)
	{
		pos += 1;
		T diff = newValue - m_mem[pos];

		while (pos)
		{
			m_mem[pos] += diff;
			pos /= 2;
		}
	}

	T value(uint32_t pos) const
	{
		return m_mem[pos + 1 + m_N];
	}

	T prefix(int pos) const
	{
		pos += 1;
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
	}
};
    
int main(int, char**)
{
    int n, K;
    char op;
	uint32_t a, b;
    scanf("%d %d", &n, &K);

	PrefixTree<int32_t> tree;

    while (K--)
    {
        scanf("\n%c %u", &op, &a);
        if (op == 'C')
        {
            scanf(" %u", &b);
            printf("%d\n", tree.prefix(b) - tree.prefix(a-1));
        }
		else
        {
			int32_t newValue = 1 - tree.value(a);
			tree.update(a, newValue);
        }
    }

    return 0;
}

