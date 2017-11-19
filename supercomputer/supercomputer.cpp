#include <iostream>
#include <cstdint>
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;

const int N = 1 << 20;
int32_t mem[N*2] = {0};

inline int prefix(uint32_t pos)
{
    int32_t  acc = 0;
    uint32_t from = pos+1;
    pos /= 2;
    while (pos)
    {
        if (from&1)
        {
            acc += mem[from];
        }

        from = pos+1;
        pos /= 2;
    }

    return -acc;
}
    

int main(int, char**)
{
    int K;
    char op;
	uint32_t a, b;
    scanf("%d %d", &K, &K);

    while (K--)
    {
        scanf("\n%c %u", &op, &a);
		a+=N;
        if (op == 'C')
        {
            scanf(" %u", &b);
            printf("%d\n", prefix(b+N) - prefix(a-1));
        }
		else
        {
			if (mem[a])
			{
				while (a)
				{
					--mem[a];
					a /= 2;
				}
			}
			else
			{
				while (a)
				{
					++mem[a];
					a /= 2;
				}
			}
        }
    }

    return 0;
}

